#pragma once
#include "UObject/NoExportTypes.h"
#include "jwt.h"
#include "Helper.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Generate Signed JWT", Keywords = "JWT"), Category = "JWT")
	void generateToken(FString key, Algorithm algorithm, UPARAM(ref) FString& JWT);
	jwt::builder<jwt::picojson_traits> jwtGenerator = jwt::create();
};