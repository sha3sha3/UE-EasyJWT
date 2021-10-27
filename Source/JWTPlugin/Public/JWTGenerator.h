//ForeFront electronics 2021
#pragma once
#include "jwt.h"
#include "Helper.h"
#include "CoreMinimal.h"
#include "JWTGenerator.generated.h"

UCLASS(BlueprintType)
class JWTPLUGIN_API UJWTGenerator : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Type", Keywords = "JWT"), Category = "JWT")//typ
	void SetType(const FString& Type);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Content Type", Keywords = "JWT"), Category = "JWT")//cty
	void SetContentType(const FString& ContentType);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Key ID", Keywords = "JWT"), Category = "JWT")//kid
	void SetKeyID(const FString& KeyID);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Subject", Keywords = "JWT"), Category = "JWT")//sub
	void SetSubject(const FString& Subject);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Audience", Keywords = "JWT"), Category = "JWT")//aud
	void SetAudience(const FString& Audience);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set ID", Keywords = "JWT"), Category = "JWT")//jti
	void SetID(const FString& ID);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Claim", Keywords = "JWT"), Category = "JWT")
	void AddClaim(const FString& Name, const FString& Value);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Claims", Keywords = "JWT"), Category = "JWT")
	void AddClaims(TMap<FString, FString> Claims);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Header Claim", Keywords = "JWT"), Category = "JWT")
	void AddHeaderClaim(const FString& Name, const FString& Value);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Header Claims", Keywords = "JWT"), Category = "JWT")
	void AddHeaderClaims(TMap<FString, FString> Claims);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Not Before", Keywords = "JWT"), Category = "JWT")//nbf
	void SetNotBefore(int32 seconds);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Expire At", Keywords = "JWT"), Category = "JWT")//exp
	void ExpireAt(int32 seconds);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Generate Signed JWT", Keywords = "JWT"), Category = "JWT")
	void GenerateToken(const FString& Key, EAlgorithm Algorithm, bool IATClaim, FString& JWT);
	
private:
	jwt::builder<jwt::picojson_traits> JwtGenerator = jwt::create();
};