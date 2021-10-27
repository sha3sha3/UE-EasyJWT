//ForeFront electronics 2021

#include "JWTPluginBPLibrary.h"
#include "JWTPlugin.h"

UJWTPluginBPLibrary::UJWTPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

TMap<FString, FString> UJWTPluginBPLibrary::GetClaims(const FString& JWTToken)
{
	TMap<FString, FString> claims;
	if (JWTToken.IsEmpty()) 
		return claims;
	try {
		auto decoded = jwt::decode(TCHAR_TO_ANSI(*JWTToken));

		for (auto& Item : decoded.get_payload_claims())
		{
			FString value = Item.second.to_json().serialize().c_str();
			claims.Add(Item.first.c_str(), value.TrimQuotes());
		}
	}
	catch (...) {}
	return claims;
}
UJWTVerifier* UJWTPluginBPLibrary::CreateVerifier(const FString& Key, EAlgorithm Algorithm)
{
	UJWTVerifier* jwtVerifier = NewObject<UJWTVerifier>();
	jwtVerifier->SetAlgorithm(Key, Algorithm);

	return jwtVerifier;
}

UJWTGenerator* UJWTPluginBPLibrary::CreateGenerator()
{

	UJWTGenerator* jwtGenerator = NewObject<UJWTGenerator>();

	return jwtGenerator;
}

