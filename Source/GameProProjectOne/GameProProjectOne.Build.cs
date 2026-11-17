// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameProProjectOne : ModuleRules
{
	public GameProProjectOne(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"GameProProjectOne",
			"GameProProjectOne/Variant_Platforming",
			"GameProProjectOne/Variant_Platforming/Animation",
			"GameProProjectOne/Variant_Combat",
			"GameProProjectOne/Variant_Combat/AI",
			"GameProProjectOne/Variant_Combat/Animation",
			"GameProProjectOne/Variant_Combat/Gameplay",
			"GameProProjectOne/Variant_Combat/Interfaces",
			"GameProProjectOne/Variant_Combat/UI",
			"GameProProjectOne/Variant_SideScrolling",
			"GameProProjectOne/Variant_SideScrolling/AI",
			"GameProProjectOne/Variant_SideScrolling/Gameplay",
			"GameProProjectOne/Variant_SideScrolling/Interfaces",
			"GameProProjectOne/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
