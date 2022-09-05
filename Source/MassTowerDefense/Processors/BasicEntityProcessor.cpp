// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEntityProcessor.h"
#include "MassCommonFragments.h"
#include "MassCommonTypes.h"
#include "../Fragments/BasicEntityFragment.h"
#include "BasicEntityProcessor.h"

UBasicEntityProcessor::UBasicEntityProcessor()
{
	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void UBasicEntityProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddRequirement<FBasicEntityFragment>(EMassFragmentAccess::ReadWrite);
}

void UBasicEntityProcessor::Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this](FMassExecutionContext& Context)
	{
		const TArrayView<FTransformFragment> TransformsList = Context.GetMutableFragmentView<FTransformFragment>();
		const TArrayView<FBasicEntityFragment> BasicFragmentsList = Context.GetMutableFragmentView<FBasicEntityFragment>();
		const float WorldDeltaTime = Context.GetDeltaTimeSeconds();

		for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); ++EntityIndex) {
			FTransform& Transform = TransformsList[EntityIndex].GetMutableTransform();
			FVector& MoveTarget = BasicFragmentsList[EntityIndex].Target;

			FVector CurrentLocation = Transform.GetLocation();
			FVector TargetVector = MoveTarget - CurrentLocation;

			if (TargetVector.Size() <= 20.0f) {
				MoveTarget = FVector(FMath::RandRange(-10.0f, 10.0f) * 1000.0f, FMath::RandRange(-10.0f, 10.0f) * 1000.0f, CurrentLocation.Z);
			}
			else {
				Transform.SetLocation(CurrentLocation + TargetVector.GetSafeNormal() * 400.0f * WorldDeltaTime);
			}
		}
	}));
}
