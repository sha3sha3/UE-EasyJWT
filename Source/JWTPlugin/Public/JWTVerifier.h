#pragma once
#include "UObject/NoExportTypes.h"
#include "jwt.h"
#include "Helper.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "JWTVerifier.generated.h"

UCLASS(BlueprintType)
class JWTPLUGIN_API UJWTVerifier : public UObject
{
	GENERATED_BODY()
public:

	void setAlgorithm(FString key,Algorithm algorithm);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Issuer", Keywords = "JWT"), Category = "JWT")//iss
	void withIssuer(FString issuer);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Subject", Keywords = "JWT"), Category = "JWT")//sub
	void withSubject(FString subject);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Audience", Keywords = "JWT"), Category = "JWT")//aud
	void withAudience(FString audience);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Leeway", Keywords = "JWT"), Category = "JWT")
	void setLeeway(int32 leeway);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Expire At", Keywords = "JWT"), Category = "JWT")//exp
	void expireAt(int32 leeway);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Not Before", Keywords = "JWT"), Category = "JWT")//nbf
	void notBefore(int32 leeway);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Issued At", Keywords = "JWT"), Category = "JWT")//iat
	void issuedAt(int32 leeway);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With ID", Keywords = "JWT"), Category = "JWT")//jti
	void withID(FString ID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "With Custom Claim", Keywords = "JWT"), Category = "JWT")
	void withCustomClaim(FString Name,FString Value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Verify JWT", Keywords = "JWT"), Category = "JWT")
	bool verifyJWT(FString JWT);
    jwt::verifier<jwt::default_clock,jwt::picojson_traits> verifier=jwt::verify();
};