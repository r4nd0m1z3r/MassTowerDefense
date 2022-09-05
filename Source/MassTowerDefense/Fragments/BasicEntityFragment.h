#pragma once

#include "CoreMinimal.h"
#include "MassEntityTypes.h"
#include "BasicEntityFragment.generated.h"

USTRUCT(BlueprintType)
struct FBasicEntityFragment : public FMassFragment {
	GENERATED_BODY()
	FVector Target;
};