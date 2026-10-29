#pragma once

#include "CoreMinimal.h"
#include "ResourceStat.generated.h"

UENUM(BlueprintType)
enum class EResourceStat : uint8
{
	Toughness,
	Hardness,
	Density,
	Elasticity,
	Strength,
	Tensility,
	
	Count UMETA(Hidden)
};

ENUM_RANGE_BY_COUNT(EResourceStat, EResourceStat::Count);
