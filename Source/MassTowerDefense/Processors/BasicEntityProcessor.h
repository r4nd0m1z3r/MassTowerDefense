// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassObserverProcessor.h"
#include "MassProcessor.h"
#include "BasicEntityProcessor.generated.h"

/**
 * 
 */
UCLASS()
class MASSTOWERDEFENSE_API UBasicEntityProcessor : public UMassProcessor
{
	GENERATED_BODY()
public:
	UBasicEntityProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
};
