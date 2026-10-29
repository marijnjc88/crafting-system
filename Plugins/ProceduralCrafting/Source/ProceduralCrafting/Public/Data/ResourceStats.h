#pragma once

#include "CoreMinimal.h"
#include "ResourceStat.h"
#include "ResourceStats.generated.h"

USTRUCT(BlueprintType)
struct PROCEDURALCRAFTING_API FResourceStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	// Ability to absorb energy and deform without fracturing
	float Toughness = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	// Ability to withstand localised scratching and denting on its surface
	float Hardness = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	// Weight per volume
	float Density = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	// Ability to bend, store energy, and use that to snap back when released
	float Elasticity = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	// Ability to withstand an applied force without breaking or deforming permanently
	float Strength = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	// Ability to resist being pulled apart
	float Tensility = 0.0f;
	
public:
	float GetStat(const EResourceStat Stat) const
	{
		switch (Stat)
		{
		case EResourceStat::Toughness:
			return Toughness;
			
		case EResourceStat::Hardness:
			return Hardness;
			
		case EResourceStat::Density:
			return Density;
			
		case EResourceStat::Elasticity:
			return Elasticity;
			
		case EResourceStat::Strength:
			return Strength;
			
		case EResourceStat::Tensility:
			return Tensility;
			
		default:
			return 0.0f;
		}
	}
};
