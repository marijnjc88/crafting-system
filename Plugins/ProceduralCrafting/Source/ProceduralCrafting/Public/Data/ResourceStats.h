#pragma once

#include "CoreMinimal.h"
#include "ResourceStats.generated.h"

USTRUCT(BlueprintType)
struct PROCEDURALCRAFTING_API FResourceStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats")
	// Ability to absorb energy and deform without fracturing
	float Toughness = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats")
	// Ability to withstand localised scratching and denting on its surface
	float Hardness = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats")
	// Weight per volume
	float Density = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats")
	// Ability to bend, store energy, and use that to snap back when released
	float Elasticity = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats")
	// Ability to withstand an applied force without breaking or deforming permanently
	float Strength = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource Stats")
	// Ability to resist being pulled apart
	float Tensility = 1.0f;
};
