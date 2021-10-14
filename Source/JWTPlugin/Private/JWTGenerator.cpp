//ForeFront electronics 2021
#include "JWTGenerator.h"


void UJWTGenerator::generateToken(FString key, Algorithm algorithm,bool IATClaim, FString& JWT) {
	auto jwtGeneratorTemp = jwtGenerator;
	if (IATClaim)
		jwtGeneratorTemp.set_issued_at(std::chrono::system_clock::now());
	switch (algorithm) {
	case Algorithm::hs256:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	/*case Algorithm::ed25519:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ed25519{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::ed448:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ed448{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::es256:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::es256{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::es384:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::es384{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::es512:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::es512{ TCHAR_TO_ANSI(*key) }).c_str())); break;*/
	case Algorithm::hs384:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs384{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::hs512:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::hs512{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	/*case Algorithm::ps256:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ps256{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::ps384:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ps384{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::ps512:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::ps512{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::rs256:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::rs256{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::rs384:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::rs384{ TCHAR_TO_ANSI(*key) }).c_str())); break;
	case Algorithm::rs512:JWT = FString(UTF8_TO_TCHAR(jwtGeneratorTemp.sign(jwt::algorithm::rs512{ TCHAR_TO_ANSI(*key) }).c_str())); break;*/
	}
	
}


void UJWTGenerator::setType(FString type) {
	jwtGenerator = jwtGenerator.set_type(TCHAR_TO_ANSI(*type));
}

void UJWTGenerator::setContentType(FString contentType) {
	jwtGenerator = jwtGenerator.set_content_type(TCHAR_TO_ANSI(*contentType));
}

void UJWTGenerator::setKeyID(FString keyID) {
	jwtGenerator = jwtGenerator.set_key_id(TCHAR_TO_ANSI(*keyID));
}

void UJWTGenerator::setSubject(FString subject) {
	jwtGenerator = jwtGenerator.set_subject(TCHAR_TO_ANSI(*subject));
}

void UJWTGenerator::setAudience(FString audience) {
	jwtGenerator = jwtGenerator.set_audience(TCHAR_TO_ANSI(*audience));
}

void UJWTGenerator::setID(FString ID) {
	jwtGenerator = jwtGenerator.set_id(TCHAR_TO_ANSI(*ID));
}

void UJWTGenerator::addClaim(FString Name,FString Value) {
	jwtGenerator = jwtGenerator.set_payload_claim(TCHAR_TO_ANSI(*Name), jwt::claim(std::string(TCHAR_TO_ANSI(*Value))));
}

void UJWTGenerator::addClaims(TMap<FString, FString> Claims) {
	for (const TPair<FString, FString>& pair : Claims)
	{
		UJWTGenerator::addClaim(pair.Key, pair.Value);
	}
}

void UJWTGenerator::addHeaderClaim(FString Name, FString Value) {
	jwtGenerator = jwtGenerator.set_header_claim(TCHAR_TO_ANSI(*Name), jwt::claim(std::string(TCHAR_TO_ANSI(*Value))));
}

void UJWTGenerator::addHeaderClaims(TMap<FString, FString> Claims) {
	for (const TPair<FString, FString>& pair : Claims)
	{
		UJWTGenerator::addHeaderClaim(pair.Key, pair.Value);
	}
}

void UJWTGenerator::setNotBefore(int32 seconds) {
	jwtGenerator = jwtGenerator.set_not_before(std::chrono::system_clock::now() + std::chrono::seconds{ seconds });
}

void UJWTGenerator::expireAt(int32 seconds) {
	jwtGenerator = jwtGenerator.set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{ seconds });
}