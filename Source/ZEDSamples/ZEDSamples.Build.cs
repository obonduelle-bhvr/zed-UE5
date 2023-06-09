//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;

public class ZEDSamples : ModuleRules
{
	public ZEDSamples(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnableUndefinedIdentifierWarnings = false;

        PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"Stereolabs",
			"ProceduralMeshComponent",
			"MeshDescription",
			"Json",
             "JsonUtilities"});

		PrivateDependencyModuleNames.AddRange(new string[] {
			 "AnimGraphRuntime",
			 });
		
	// Uncomment if you are using Slate UI
	// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

	// Uncomment if you are using online features
	// PrivateDependencyModuleNames.Add("OnlineSubsystem");

	// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
}
}
