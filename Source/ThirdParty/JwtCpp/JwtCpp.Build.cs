// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

using UnrealBuildTool;
using System.IO;

public class JwtCpp : ModuleRules
{
	public JwtCpp(ReadOnlyTargetRules Target) : base(Target)
	{
        Type = ModuleType.External;
        CppStandard = CppStandardVersion.Cpp17;
        PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
        PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				Path.Combine(Path.Combine(ModuleDirectory, "include"))
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
                "OpenSSL"
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				
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
