// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Subsystems/EngineSubsystem.h"
#include "EasyJwt.h"
#include "GeneratorAlgorithm.h"
#include "VerifierAlgorithm.h"
#include "EasyJwtSubsystem.generated.h"


UCLASS()
class EASYJWT_API UEasyJwtSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()


public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Initialize JWT Verifier", Keywords = "JWT"), Category = "EasyJWT|Verifier")
		void InitVerifier(const FString& Key, EVerifierAlgorithm Algorithm);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Issuer", Keywords = "JWT"), Category = "EasyJWT|Verifier") //iss
		void WithIssuer(const FString& Issuer);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Subject", Keywords = "JWT"), Category = "EasyJWT|Verifier") //sub
		void WithSubject(const FString& Subject);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Audience", Keywords = "JWT"), Category = "EasyJWT|Verifier") //aud
		void WithAudience(const FString& Audience);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Leeway", Keywords = "JWT"), Category = "EasyJWT|Verifier")
		void SetLeeway(int32 Leeway);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With ID", Keywords = "JWT"), Category = "EasyJWT|Verifier") //jti
		void WithID(const FString& ID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Custom Claim", Keywords = "JWT"), Category = "EasyJWT|Verifier")
		void WithCustomClaim(const FString& Name, const FString& Value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Verify JWT", Keywords = "JWT"), Category = "EasyJWT|Verifier")
		bool VerifyJWT(const FString& Input);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Claims", Keywords = "JWT"), Category = "EasyJWT|Verifier")
		TMap<FString, FString> GetClaims(const FString& JWTToken);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Initialize JWT Generator", Keywords = "JWT"), Category = "EasyJWT|Generator")
		void InitGenerator(const FString& Key, EGeneratorAlgorithm Algorithm);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Type", Keywords = "JWT"), Category = "EasyJWT|Generator")//typ
		void SetType(const FString& Type);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Content Type", Keywords = "JWT"), Category = "EasyJWT|Generator")//cty
		void SetContentType(const FString& ContentType);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Key ID", Keywords = "JWT"), Category = "EasyJWT|Generator")//kid
		void SetKeyID(const FString& KeyID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Subject", Keywords = "JWT"), Category = "EasyJWT|Generator")//sub
		void SetSubject(const FString& Subject);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Audience", Keywords = "JWT"), Category = "EasyJWT|Generator")//aud
		void SetAudience(const FString& Audience);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set ID", Keywords = "JWT"), Category = "EasyJWT|Generator")//jti
		void SetID(const FString& ID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Generate Signed JWT", Keywords = "JWT"), Category = "JWT")
		FString GenerateJwtToken(bool IATClaim , TMap<FString, FString> Claims , TMap<FString, FString> HeaderClaims, int NotBeforeSec = 0, int ExpireAfterSec = 900);
	
	TSharedPtr<FEasyJwtModule> GetEasyJwt();
private:
	TSharedPtr<FEasyJwtModule> EasyJwt = nullptr;

};
