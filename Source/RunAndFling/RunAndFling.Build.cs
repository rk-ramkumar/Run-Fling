// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RunAndFling : ModuleRules
{
	public RunAndFling(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
  {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "OnlineSubsystem",
            "OnlineSubsystemEOS",
            "OnlineSubsystemUtils"
  });
	}
}
