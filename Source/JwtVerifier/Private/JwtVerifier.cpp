// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

#include "JwtVerifier.h"

DEFINE_LOG_CATEGORY(LogJwtVerifier);
#define LOCTEXT_NAMESPACE "FJwtVerifierModule"

FJwtVerifierModule* FJwtVerifierModule::JwtVerifierSingleton = nullptr;

void FJwtVerifierModule::StartupModule()
{
	UE_LOG(LogJwtVerifier, Display, TEXT("JwtVerifier Startup"));
	if (!JwtVerifierSingleton)
		FJwtVerifierModule::JwtVerifierSingleton = this;

}

void FJwtVerifierModule::ShutdownModule()
{
	UE_LOG(LogJwtVerifier, Display, TEXT("JwtVerifier Shutdown"));

}

FJwtVerifierModule& FJwtVerifierModule::Get()
{
	if (JwtVerifierSingleton == nullptr)
	{
		check(IsInGameThread());
		FModuleManager::LoadModuleChecked<FJwtVerifierModule>("FJwtVerifierModule");
	}
	check(JwtVerifierSingleton);
	return *JwtVerifierSingleton;
}

void FJwtVerifierModule::InitVerifier(const FString& Key, EVerifierAlgorithm Algorithm) {
	try
	{
		switch (Algorithm) {
		case EVerifierAlgorithm::HS256: Verifier = Verifier.allow_algorithm(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*Key) }); break;
		case EVerifierAlgorithm::HS384: Verifier = Verifier.allow_algorithm(jwt::algorithm::hs384{ TCHAR_TO_ANSI(*Key) }); break;
		case EVerifierAlgorithm::HS512: Verifier = Verifier.allow_algorithm(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*Key) }); break;
		case EVerifierAlgorithm::RS256: Verifier = Verifier.allow_algorithm(jwt::algorithm::rs256(TCHAR_TO_ANSI(*Key), "", "", "")); break;
		case EVerifierAlgorithm::RS384: Verifier = Verifier.allow_algorithm(jwt::algorithm::rs384(TCHAR_TO_ANSI(*Key), "", "", "")); break;
		case EVerifierAlgorithm::RS512: Verifier = Verifier.allow_algorithm(jwt::algorithm::rs512(TCHAR_TO_ANSI(*Key), "", "", "")); break;
		}
	}
	catch (...) {}
}

bool FJwtVerifierModule::VerifyJWT(const FString& Input) {
	try {
		Verifier.jwtVerify(jwt::decode(TCHAR_TO_ANSI(*Input)));
	}
	catch (const std::exception& ec) {
		UE_LOG(LogJwtVerifier, Error, TEXT("Error:  %d"), *ec.what());
		return false;
	}

	return true;
}

TMap<FString, FString> FJwtVerifierModule::GetClaims(const FString& JWTToken)
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

void FJwtVerifierModule::WithIssuer(const FString& Issuer) {
	Verifier = Verifier.with_issuer(TCHAR_TO_ANSI(*Issuer));
}

void FJwtVerifierModule::SetLeeway(int32 Leeway) {
	Verifier = Verifier.leeway(Leeway);
}

void FJwtVerifierModule::WithAudience(const FString& Audience) {
	Verifier = Verifier.with_audience(TCHAR_TO_ANSI(*Audience));
}

void FJwtVerifierModule::WithSubject(const FString& Subject) {
	Verifier = Verifier.with_subject(TCHAR_TO_ANSI(*Subject));
}

void FJwtVerifierModule::WithID(const FString& ID) {
	Verifier = Verifier.with_id(TCHAR_TO_ANSI(*ID));
}

void FJwtVerifierModule::WithCustomClaim(const FString& Name, const FString& Value) {
	Verifier = Verifier.with_custom_claim(TCHAR_TO_ANSI(*Name), TCHAR_TO_ANSI(*Value));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FJwtVerifierModule, JwtVerifier)