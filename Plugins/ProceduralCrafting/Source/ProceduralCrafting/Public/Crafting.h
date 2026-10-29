#pragma once

struct FCraftingResourceInput;
struct FResourceAggregation;
struct FResourceStatAggregation;
struct FWeaponStats;
struct FWeaponStatWeights;

class UWeaponType;

enum class EResourceStat : uint8;

class FCrafting
{
public:
	static FResourceAggregation AggregateResources(const TArray<FCraftingResourceInput>& Resources);
	
	static FWeaponStats GenerateWeaponStats(const FResourceAggregation& Aggregation, const UWeaponType* WeaponType);
	
private:
	static FResourceStatAggregation AggregateStats(const TArray<FCraftingResourceInput>& Resources, const EResourceStat Stat);
	
	static float CalculateWeaponStat(const FResourceAggregation& Aggregation, const FWeaponStatWeights& StatWeights);
};