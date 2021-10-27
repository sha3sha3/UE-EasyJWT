//ForeFront electronics 2021
#include "JWTGenerator.h"


void UJWTGenerator::GenerateToken(const FString& Key, EAlgorithm Algorithm, bool IATClaim, FString& JWT) {
	auto jwtGeneratorTemp = JwtGenerator;
	if (IATClaim)
	{
		jwtGeneratorTemp.set_issued_at(std::chrono::system_clock::now());
	}
	
	try
	{
		switch (Algorithm) {
			case EAlgorithm::hs256: JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*Key) }).c_str())); break;
			case EAlgorithm::hs384: JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs384{ TCHAR_TO_ANSI(*Key) }).c_str())); break;
			case EAlgorithm::hs512: JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs512{ TCHAR_TO_ANSI(*Key) }).c_str())); break;
			case EAlgorithm::rs256: JWT = FString(jwtGeneratorTemp.sign(jwt::algorithm::rs256("", TCHAR_TO_ANSI(*Key), "", "")).c_str()); break;
			case EAlgorithm::rs384: JWT = FString(jwtGeneratorTemp.sign(jwt::algorithm::rs384("", TCHAR_TO_ANSI(*Key), "", "")).c_str()); break;
			case EAlgorithm::rs512: JWT = FString(jwtGeneratorTemp.sign(jwt::algorithm::rs512("", TCHAR_TO_ANSI(*Key), "", "")).c_str()); break;
			/*case Algorithm::ed25519:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ed25519{ TCHAR_TO_ANSI(*key) }).c_str())); break;
			case Algorithm::ed448:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ed448{ TCHAR_TO_ANSI(*key) }).c_str())); break;
			case Algorithm::es256:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::es256{ TCHAR_TO_ANSI(*key) }).c_str())); break;
			case Algorithm::es384:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::es384{ TCHAR_TO_ANSI(*key) }).c_str())); break;
			case Algorithm::es512:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::es512{ TCHAR_TO_ANSI(*key) }).c_str())); break;
			case Algorithm::ps256:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ps256{ TCHAR_TO_ANSI(*key) }).c_str())); break;
			case Algorithm::ps384:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ps384{ TCHAR_TO_ANSI(*key) }).c_str())); break;
			case Algorithm::ps512:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ps512{ TCHAR_TO_ANSI(*key) }).c_str())); break; */
		}
	} catch(...) {}
}

void UJWTGenerator::SetType(const FString& Type) {
	JwtGenerator = JwtGenerator.set_type(TCHAR_TO_ANSI(*Type));
}

void UJWTGenerator::SetContentType(const FString& ContentType) {
	JwtGenerator = JwtGenerator.set_content_type(TCHAR_TO_ANSI(*ContentType));
}

void UJWTGenerator::SetKeyID(const FString& KeyID) {
	JwtGenerator = JwtGenerator.set_key_id(TCHAR_TO_ANSI(*KeyID));
}

void UJWTGenerator::SetSubject(const FString& Subject) {
	JwtGenerator = JwtGenerator.set_subject(TCHAR_TO_ANSI(*Subject));
}

void UJWTGenerator::SetAudience(const FString& Audience) {
	JwtGenerator = JwtGenerator.set_audience(TCHAR_TO_ANSI(*Audience));
}

void UJWTGenerator::SetID(const FString& ID) {
	JwtGenerator = JwtGenerator.set_id(TCHAR_TO_ANSI(*ID));
}

void UJWTGenerator::AddClaim(const FString& Name, const FString& Value) {
	JwtGenerator = JwtGenerator.set_payload_claim(TCHAR_TO_ANSI(*Name), jwt::claim(std::string(TCHAR_TO_ANSI(*Value))));
}

void UJWTGenerator::AddClaims(TMap<FString, FString> Claims) {
	for (const TPair<FString, FString>& pair : Claims)
	{
		UJWTGenerator::AddClaim(pair.Key, pair.Value);
	}
}

void UJWTGenerator::AddHeaderClaim(const FString& Name, const FString& Value) {
	JwtGenerator = JwtGenerator.set_header_claim(TCHAR_TO_ANSI(*Name), jwt::claim(std::string(TCHAR_TO_ANSI(*Value))));
}

void UJWTGenerator::AddHeaderClaims(TMap<FString, FString> Claims) {
	for (const TPair<FString, FString>& pair : Claims)
	{
		UJWTGenerator::AddHeaderClaim(pair.Key, pair.Value);
	}
}

void UJWTGenerator::SetNotBefore(int32 Seconds) {
	JwtGenerator = JwtGenerator.set_not_before(std::chrono::system_clock::now() + std::chrono::seconds{ Seconds });
}

void UJWTGenerator::ExpireAt(int32 Seconds) {
	JwtGenerator = JwtGenerator.set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{ Seconds });
}