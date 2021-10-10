#include "JWTGenerator.h"

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