#pragma once

#include "CoreMinimal.h"
#include "ResourceStatAggregation.h"
#include "ResourceAggregation.generated.h"

USTRUCT(BlueprintType)
struct PROCEDURALCRAFTING_API FResourceAggregation
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, Category = "Aggregation")
	TMap<EResourceStat, FResourceStatAggregation> Stats;
};
