// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

#pragma once

#include "VerifierAlgorithm.h"
#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#include "jwt.h"
THIRD_PARTY_INCLUDES_END
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogJwtVerifier, Log, All);

class JWTVERIFIER_API FJwtVerifierModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static FJwtVerifierModule& Get();

public:

	void InitVerifier(const FString& Key, EVerifierAlgorithm algorithm);

	void WithIssuer(const FString& Issuer);

	void WithSubject(const FString& Subject);

	void WithAudience(const FString& Audience);

	void SetLeeway(int32 Leeway);

	void WithID(const FString& ID);

	void WithCustomClaim(const FString& Name, const FString& Value);

	bool VerifyJWT(const FString& Input);

	TMap<FString, FString> GetClaims(const FString& JWTToken);
private:

	static FJwtVerifierModule* JwtVerifierSingleton;

	jwt::verifier<jwt::default_clock, jwt::picojson_traits> Verifier = jwt::jwtVerify();
};
