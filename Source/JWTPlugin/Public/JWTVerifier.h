//ForeFront electronics 2021
#pragma once
#include "UObject/NoExportTypes.h"
#include "jwt.h"
#include "Helper.h"
#include "CoreMinimal.h"
#include "JWTVerifier.generated.h"

#ifdef verify
#undef verify//assertion macros in ue4
#endif

UCLASS(BlueprintType)
class JWTPLUGIN_API UJWTVerifier : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Algorithm", Keywords = "JWT"), Category = "JWT") //alg
	void SetAlgorithm(const FString& Key, EAlgorithm algorithm);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Issuer", Keywords = "JWT"), Category = "JWT") //iss
	void WithIssuer(const FString& Issuer);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Subject", Keywords = "JWT"), Category = "JWT") //sub
	void WithSubject(const FString& Subject);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Audience", Keywords = "JWT"), Category = "JWT") //aud
	void WithAudience(const FString& Audience);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Leeway", Keywords = "JWT"), Category = "JWT")
	void SetLeeway(int32 Leeway);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With ID", Keywords = "JWT"), Category = "JWT") //jti
	void WithID(const FString& ID);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Custom Claim", Keywords = "JWT"), Category = "JWT")
	void WithCustomClaim(const FString& Name, const FString& Value);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Verify JWT", Keywords = "JWT"), Category = "JWT")
	bool VerifyJWT(const FString& Input);
private:
    jwt::verifier<jwt::default_clock,jwt::picojson_traits> Verifier = jwt::verify();
};