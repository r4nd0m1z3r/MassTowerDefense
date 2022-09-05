// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEntityTrait.h"

void UBasicEntityTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const
{
	BuildContext.AddFragment<FBasicEntityFragment>();
}
