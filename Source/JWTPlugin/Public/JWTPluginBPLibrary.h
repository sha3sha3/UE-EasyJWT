//ForeFront electronics 2021

#pragma once
#include "jwt.h"
#include "Helper.h"
#include "JWTVerifier.h"
#include "JWTGenerator.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JWTPluginBPLibrary.generated.h"


UCLASS()
class JWTPLUGIN_API UJWTPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Claims", Keywords = "JWT"), Category = "JWT")
	static TMap<FString, FString> GetClaims(const FString& JWTToken);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create JWT Verifier", Keywords = "JWT"), Category = "JWT")
	static UJWTVerifier* CreateVerifier(const FString& Key, EAlgorithm Algorithm);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create JWT Generator", Keywords = "JWT"), Category = "JWT")
	static UJWTGenerator* CreateGenerator();
};
