//ForeFront electronics 2021

#include "JWTPluginBPLibrary.h"
#include "JWTPlugin.h"

UJWTPluginBPLibrary::UJWTPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

TMap<FString, FString> UJWTPluginBPLibrary::GetClaims(const FString JWTToken)
{
	TMap<FString, FString> claims;
	if (JWTToken.IsEmpty()) 
		return claims;
	try {
		auto decoded = jwt::decode(TCHAR_TO_ANSI(*JWTToken));

		for (auto& Item : decoded.get_payload_claims())
		{
			claims.Add(Item.first.c_str(), Item.second.to_json().serialize().c_str());
		}
	}
	catch (...) {}
	return claims;
}
UJWTVerifier* UJWTPluginBPLibrary::CreateVerifier(FString key, Algorithm algorithm)
{

	UJWTVerifier* jwtVerifier = NewObject<UJWTVerifier>();
	jwtVerifier->setAlgorithm(key, algorithm);

	return jwtVerifier;
}

UJWTGenerator* UJWTPluginBPLibrary::CreateGenerator()
{

	UJWTGenerator* jwtGenerator = NewObject<UJWTGenerator>();

	return jwtGenerator;
}

