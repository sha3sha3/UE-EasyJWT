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
	void setType(FString type);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Content Type", Keywords = "JWT"), Category = "JWT")//cty
	void setContentType(FString contentType);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Key ID", Keywords = "JWT"), Category = "JWT")//kid
	void setKeyID(FString keyID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Subject", Keywords = "JWT"), Category = "JWT")//sub
	void setSubject(FString Subject);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Audience", Keywords = "JWT"), Category = "JWT")//aud
	void setAudience(FString Audience);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set ID", Keywords = "JWT"), Category = "JWT")//jti
	void setID(FString ID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Claim", Keywords = "JWT"), Category = "JWT")
	void addClaim(FString Name, FString Value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Claims", Keywords = "JWT"), Category = "JWT")
	void addClaims(TMap<FString, FString> Claims);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Header Claim", Keywords = "JWT"), Category = "JWT")
	void addHeaderClaim(FString Name, FString Value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Header Claims", Keywords = "JWT"), Category = "JWT")
	void addHeaderClaims(TMap<FString, FString> Claims);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Not Before", Keywords = "JWT"), Category = "JWT")//nbf
	void setNotBefore(int32 seconds);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Expire At", Keywords = "JWT"), Category = "JWT")//exp
	void expireAt(int32 seconds);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Generate Signed JWT", Keywords = "JWT"), Category = "JWT")
	void generateToken(FString key, Algorithm algorithm,bool IATClaim, FString& JWT);
private:
	jwt::builder<jwt::picojson_traits> jwtGenerator = jwt::create();
};