// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TheRoomYouStayedIn : ModuleRules
{
	public TheRoomYouStayedIn(ReadOnlyTargetRules Target) : base(Target)
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
			"TheRoomYouStayedIn",
			"TheRoomYouStayedIn/Variant_Platforming",
			"TheRoomYouStayedIn/Variant_Platforming/Animation",
			"TheRoomYouStayedIn/Variant_Combat",
			"TheRoomYouStayedIn/Variant_Combat/AI",
			"TheRoomYouStayedIn/Variant_Combat/Animation",
			"TheRoomYouStayedIn/Variant_Combat/Gameplay",
			"TheRoomYouStayedIn/Variant_Combat/Interfaces",
			"TheRoomYouStayedIn/Variant_Combat/UI",
			"TheRoomYouStayedIn/Variant_SideScrolling",
			"TheRoomYouStayedIn/Variant_SideScrolling/AI",
			"TheRoomYouStayedIn/Variant_SideScrolling/Gameplay",
			"TheRoomYouStayedIn/Variant_SideScrolling/Interfaces",
			"TheRoomYouStayedIn/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
