#include "Crafting.h"

#include "Data/ResourceAggregation.h"
#include "Data/CraftingResourceInput.h"
#include "Data/CraftingResource.h"
#include "Data/WeaponStats.h"
#include "Data/WeaponStatWeights.h"
#include "Data/WeaponType.h"
#include "ProceduralCraftingSettings.h"

FResourceAggregation FCrafting::AggregateResources(const TArray<FCraftingResourceInput>& Resources)
{
	FResourceAggregation Result;
	
	for (const EResourceStat Stat : TEnumRange<EResourceStat>())
		Result.Stats.Add(Stat, AggregateStats(Resources, Stat));
	
	return Result;
}

FResourceStatAggregation FCrafting::AggregateStats(const TArray<FCraftingResourceInput>& Resources, const EResourceStat Stat)
{
	FResourceStatAggregation Result;
	Result.Stat = Stat;
	
	float TotalAmount = 0.0f;
	float TotalContribution = 0.0f;
	
	float HighestContribution = -1.0f;
	float HighestValue = -1.0f;
	
	for (const auto& [Resource, Amount] : Resources)
	{
		if (!Resource || Amount <= 0)
			continue;
		
		const float Value = Resource->GetStat(Stat);
		const float FAmount = static_cast<float>(Amount);
		
		const float Contribution = Value * FAmount;
		
		TotalAmount += FAmount;
		TotalContribution += Contribution;
		
		if (Contribution > HighestContribution)
		{
			HighestContribution = Contribution;
			Result.MostInfluential = Resource;
		}
		if (Value > HighestValue)
		{
			HighestValue = Value;
			Result.Highest = Resource;
		}
	}
	
	if (!FMath::IsNearlyZero(TotalAmount))
	{
		Result.Average = TotalContribution / TotalAmount;
	}
	
	return Result;
}

FWeaponStats FCrafting::GenerateWeaponStats(const FResourceAggregation& Aggregation, const UWeaponType* WeaponType)
{
	FWeaponStats Result;
	
	if (!WeaponType)
		return Result;
	
	const UProceduralCraftingSettings* Settings = GetDefault<UProceduralCraftingSettings>();
	const float ScoreMultiplier = 1.0f / FMath::Max(Settings->NeutralScore, 0.001f);
	
	const FWeaponStats& Base = WeaponType->BaseStats;
	
	const float DamageScore = CalculateWeaponStat(Aggregation, WeaponType->DamageWeights);
	const float DurabilityScore = CalculateWeaponStat(Aggregation, WeaponType->DurabilityWeights);
	const float AttackSpeedScore = CalculateWeaponStat(Aggregation, WeaponType->AttackSpeedWeights);
	
	Result.Damage = Base.Damage * DamageScore * ScoreMultiplier + Settings->DamageOffset;
	Result.Durability = Base.Durability * DurabilityScore * ScoreMultiplier + Settings->DurabilityOffset;
	Result.AttackSpeed = Base.AttackSpeed * AttackSpeedScore * ScoreMultiplier + Settings->AttackSpeedOffset;
	
	return Result;
}

float FCrafting::CalculateWeaponStat(const FResourceAggregation& Aggregation, const FWeaponStatWeights& StatWeights)
{
	float TotalWeightedValue = 0.0f;
	float TotalWeight = 0.0f;
	
	for (const EResourceStat Stat : TEnumRange<EResourceStat>())
	{
		const FWeaponStatInfluence* Influence = StatWeights.Weights.Find(Stat);
		
		if (!Influence)
			continue;
		
		const float Weight = Influence->Weight;
		
		if (!FMath::IsFinite(Weight) || Weight <= 0.0f)
			continue;
		
		const FResourceStatAggregation* AggregatedStat = Aggregation.Stats.Find(Stat);
		
		if (!AggregatedStat)
			continue;
		
		const float Value = AggregatedStat->Average;
		
		if (!FMath::IsFinite(Value))
			continue;
		
		const float EffectiveValue = Influence->bInverse ? 100.0f - Value : Value;
		
		TotalWeightedValue += EffectiveValue * Weight;
		TotalWeight += Weight;
	}
	
	if (TotalWeight <= 0.0f)
		return 0.0f;
	
	return TotalWeightedValue / TotalWeight;
}
