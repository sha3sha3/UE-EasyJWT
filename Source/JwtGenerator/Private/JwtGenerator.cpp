// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

#include "JwtGenerator.h"

DEFINE_LOG_CATEGORY(LogJwtGenerator);
#define LOCTEXT_NAMESPACE "FJwtGeneratorModule"

FJwtGeneratorModule* FJwtGeneratorModule::JwtGeneratorSingleton = nullptr;

void FJwtGeneratorModule::StartupModule()
{
	UE_LOG(LogJwtGenerator, Display, TEXT("JwtGenerator Startup"));
	if (!JwtGeneratorSingleton)
		FJwtGeneratorModule::JwtGeneratorSingleton = this;

}

void FJwtGeneratorModule::ShutdownModule()
{
	UE_LOG(LogJwtGenerator, Display, TEXT("JwtGenerator Shutdown"));

}

FJwtGeneratorModule& FJwtGeneratorModule::Get()
{
	if (JwtGeneratorSingleton == nullptr)
	{
		check(IsInGameThread());
		FModuleManager::LoadModuleChecked<FJwtGeneratorModule>("FJwtGeneratorModule");
	}
	check(JwtGeneratorSingleton);
	return *JwtGeneratorSingleton;
}

FString FJwtGeneratorModule::GenerateJwtToken(bool IATClaim, int NotBeforeSec, int ExpireAfterSec, TMap<FString, FString> Claims, TMap<FString, FString> HeaderClaims)
{
	auto jwtGeneratorTemp = JwtGenerator;//create a copy

	if (IATClaim)
	{
		jwtGeneratorTemp.set_issued_at(std::chrono::system_clock::now());
	}

	jwtGeneratorTemp.set_not_before(std::chrono::system_clock::now() + std::chrono::seconds{ NotBeforeSec });
	jwtGeneratorTemp.set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{ ExpireAfterSec });

	for (const TPair<FString, FString>& pair : Claims)
	{
		jwtGeneratorTemp.set_payload_claim(TCHAR_TO_ANSI(*pair.Key), jwt::claim(std::string(TCHAR_TO_ANSI(*pair.Value))));
	}

	for (const TPair<FString, FString>& pair : HeaderClaims)
	{
		jwtGeneratorTemp.set_header_claim(TCHAR_TO_ANSI(*pair.Key), jwt::claim(std::string(TCHAR_TO_ANSI(*pair.Value))));
	}

	try
	{
		switch (GeneratorAlgo) {
		case EGeneratorAlgorithm::HS256: return FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*Key) }).c_str())); break;
		case EGeneratorAlgorithm::HS384: return FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs384{ TCHAR_TO_ANSI(*Key) }).c_str())); break;
		case EGeneratorAlgorithm::HS512: return FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs512{ TCHAR_TO_ANSI(*Key) }).c_str())); break;
		case EGeneratorAlgorithm::RS256: return FString(jwtGeneratorTemp.sign(jwt::algorithm::rs256("", TCHAR_TO_ANSI(*Key), "", "")).c_str()); break;
		case EGeneratorAlgorithm::RS384: return FString(jwtGeneratorTemp.sign(jwt::algorithm::rs384("", TCHAR_TO_ANSI(*Key), "", "")).c_str()); break;
		case EGeneratorAlgorithm::RS512: return FString(jwtGeneratorTemp.sign(jwt::algorithm::rs512("", TCHAR_TO_ANSI(*Key), "", "")).c_str()); break;
		}
	}
	catch (...) 
	{ 
		UE_LOG(LogJwtGenerator, Error, TEXT("Error generating JWT."));
		return ""; 
	}

	return "";
}

void FJwtGeneratorModule::InitGenerator(const FString& InKey, EGeneratorAlgorithm Algorithm)
{
	Key = InKey;
	GeneratorAlgo = Algorithm;
}

void FJwtGeneratorModule::SetType(const FString& Type) {
	JwtGenerator = JwtGenerator.set_type(TCHAR_TO_ANSI(*Type));
}

void FJwtGeneratorModule::SetContentType(const FString& ContentType) {
	JwtGenerator = JwtGenerator.set_content_type(TCHAR_TO_ANSI(*ContentType));
}

void FJwtGeneratorModule::SetKeyID(const FString& KeyID) {
	JwtGenerator = JwtGenerator.set_key_id(TCHAR_TO_ANSI(*KeyID));
}

void FJwtGeneratorModule::SetSubject(const FString& Subject) {
	JwtGenerator = JwtGenerator.set_subject(TCHAR_TO_ANSI(*Subject));
}

void FJwtGeneratorModule::SetAudience(const FString& Audience) {
	JwtGenerator = JwtGenerator.set_audience(TCHAR_TO_ANSI(*Audience));
}

void FJwtGeneratorModule::SetID(const FString& ID) {
	JwtGenerator = JwtGenerator.set_id(TCHAR_TO_ANSI(*ID));
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FJwtGeneratorModule, JwtGenerator)