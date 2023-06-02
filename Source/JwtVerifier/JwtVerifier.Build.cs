// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

using UnrealBuildTool;
using System.IO;

public class JwtVerifier : ModuleRules
{
	public JwtVerifier(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        CppStandard = CppStandardVersion.Cpp17;

        PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
				Path.Combine(Path.Combine(ModuleDirectory, "Public"))
            }
            );


        PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"JwtCpp"
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
		bEnableExceptions = true;
	}
}
