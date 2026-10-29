#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ProceduralCraftingFunctionLibrary.generated.h"

struct FCraftingResourceInput;
struct FResourceAggregation;
struct FResourceStats;
struct FWeaponStats;

class UWeaponType;

// Wrapper that exposes algorithm to blueprints
UCLASS()
class PROCEDURALCRAFTING_API UProceduralCraftingFunctionLibrary
	: public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Procedural Crafting")
	static FResourceAggregation AggregateResources(const TArray<FCraftingResourceInput>& Resources);
	
	UFUNCTION(BlueprintCallable, Category = "Procedural Crafting")
	static FWeaponStats GenerateWeaponStats(const FResourceAggregation& Aggregation, const UWeaponType* WeaponType);
};
