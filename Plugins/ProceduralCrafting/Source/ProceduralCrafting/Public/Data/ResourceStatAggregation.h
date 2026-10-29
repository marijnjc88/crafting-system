#pragma once

#include "CoreMinimal.h"
#include "ResourceStat.h"
#include "ResourceStatAggregation.generated.h"

class UCraftingResource;

USTRUCT(BlueprintType)
struct PROCEDURALCRAFTING_API FResourceStatAggregation
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, Category = "Aggregation")
	EResourceStat Stat;
	
	UPROPERTY(BlueprintReadOnly, Category = "Aggregation")
	float Average = 0.0f;
	
	UPROPERTY(BlueprintReadOnly, Category = "Aggregation")
	TObjectPtr<UCraftingResource> Highest = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "Aggregation")
	TObjectPtr<UCraftingResource> MostInfluential = nullptr;
};
