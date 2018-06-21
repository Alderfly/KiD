#pragma once

#include "CoreMinimal.h"
#include "GlobalDefinitions.generated.h"

UENUM(BlueprintType)
enum class ETeam : uint8
{
	None,
	Player,
	Team1
};

UENUM()
enum class EAttackStatus : uint8
{
	Reloading,
	Ready
};