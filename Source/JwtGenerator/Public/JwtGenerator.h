// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

#pragma once

#include "GeneratorAlgorithm.h"
#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#include "jwt.h"
THIRD_PARTY_INCLUDES_END
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogJwtGenerator, Log, All);

class JWTGENERATOR_API FJwtGeneratorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static FJwtGeneratorModule& Get();

	void SetType(const FString& Type);

	void SetContentType(const FString& ContentType);

	void SetKeyID(const FString& KeyID);

	void SetSubject(const FString& Subject);

	void SetAudience(const FString& Audience);

	void SetID(const FString& ID);

	FString GenerateJwtToken(bool IATClaim, int NotBeforeSec, int ExpireAfterSec, TMap<FString, FString> Claims, TMap<FString, FString> HeaderClaims);

	void InitGenerator(const FString& Key, EGeneratorAlgorithm Algorithm);
	
private:

	jwt::builder<jwt::picojson_traits> JwtGenerator = jwt::create();

	static FJwtGeneratorModule* JwtGeneratorSingleton;

	EGeneratorAlgorithm GeneratorAlgo = EGeneratorAlgorithm::HS256;

	FString Key = "";
};
