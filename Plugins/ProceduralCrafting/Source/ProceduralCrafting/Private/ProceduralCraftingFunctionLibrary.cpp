#include "ProceduralCraftingFunctionLibrary.h"
#include "Data/CraftingResourceInput.h"
#include "Data/ResourceAggregation.h"
#include "Data/WeaponStats.h"
#include "Data/WeaponType.h"
#include "Crafting.h"

FResourceAggregation UProceduralCraftingFunctionLibrary::AggregateResources(
	const TArray<FCraftingResourceInput>& Resources)
{
	return FCrafting::AggregateResources(Resources);
}

FWeaponStats UProceduralCraftingFunctionLibrary::GenerateWeaponStats(const FResourceAggregation& Aggregation, const UWeaponType* WeaponType)
{
	return FCrafting::GenerateWeaponStats(Aggregation, WeaponType);
}
