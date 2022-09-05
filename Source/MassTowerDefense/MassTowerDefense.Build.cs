// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MassTowerDefense : ModuleRules
{
	public MassTowerDefense(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {
			"MassEntity",
			"StructUtils",
			"MassCommon",
			"MassMovement",
			"MassActors",
			"MassSpawner",
			"MassGameplayDebug",
			"MassSignals",
			"MassCrowd",
			"MassActors",
			"MassSpawner",
			"MassRepresentation",
			"MassReplication",
			"MassNavigation" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
