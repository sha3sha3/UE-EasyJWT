#include "JWTVerifier.h"

void UJWTVerifier::setAlgorithm(FString key, Algorithm algorithm) {

	switch (algorithm) {
	case Algorithm::hs256:verifier = verifier.allow_algorithm(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*key) }); break;
	/*case Algorithm::ed25519:verifier = verifier.allow_algorithm(jwt::algorithm::ed25519{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::ed448:verifier = verifier.allow_algorithm(jwt::algorithm::ed448{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::es256:verifier = verifier.allow_algorithm(jwt::algorithm::es256{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::es384:verifier = verifier.allow_algorithm(jwt::algorithm::es384{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::es512:verifier = verifier.allow_algorithm(jwt::algorithm::es512{ TCHAR_TO_ANSI(*key) }); break;*/
	case Algorithm::hs384:verifier = verifier.allow_algorithm(jwt::algorithm::hs384{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::hs512:verifier = verifier.allow_algorithm(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*key) }); break;
	/*case Algorithm::ps256:verifier = verifier.allow_algorithm(jwt::algorithm::hs512{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::ps384:verifier = verifier.allow_algorithm(jwt::algorithm::ps384{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::ps512:verifier = verifier.allow_algorithm(jwt::algorithm::ps512{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::rs256:verifier = verifier.allow_algorithm(jwt::algorithm::rs256{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::rs384:verifier = verifier.allow_algorithm(jwt::algorithm::rs384{ TCHAR_TO_ANSI(*key) }); break;
	case Algorithm::rs512:verifier = verifier.allow_algorithm(jwt::algorithm::rs512{ TCHAR_TO_ANSI(*key) }); break;*/
	}	
}

bool UJWTVerifier::verifyJWT(FString jwt) {

	try {
		
		return verifier.verify(jwt::decode(TCHAR_TO_ANSI(*jwt)));
	}
	catch (const std::exception& ec) {
		UE_LOG(LogTemp, Error,TEXT("Error:  %d"),*ec.what());
		return false;
	}
	/*Not a good idea o use try and catch but looking for a solution*/
	
}

void UJWTVerifier::withIssuer(FString issuer) {
	verifier = verifier.with_issuer(TCHAR_TO_ANSI(*issuer));
}

void UJWTVerifier::setLeeway(int32 leeway) {
	verifier = verifier.leeway(leeway);
}
void UJWTVerifier::withAudience(FString audience) {
	verifier = verifier.with_audience(TCHAR_TO_ANSI(*audience));
}

void UJWTVerifier::withSubject(FString subject) {
	verifier = verifier.with_subject(TCHAR_TO_ANSI(*subject));
}

void UJWTVerifier::withID(FString ID) {
	verifier = verifier.with_id(TCHAR_TO_ANSI(*ID));
}
void UJWTVerifier::withCustomClaim(FString Name,FString Value) {
	verifier = verifier.with_custom_claim(TCHAR_TO_ANSI(*Name), TCHAR_TO_ANSI(*Value));
}