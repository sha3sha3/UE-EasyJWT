//ForeFront electronics 2021
#include "JWTVerifier.h"

void UJWTVerifier::SetAlgorithm(const FString& Key, EAlgorithm Algorithm) {
	try
	{
		switch (Algorithm) {
			case EAlgorithm::hs256: Verifier = Verifier.allow_algorithm(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*Key) }); break;
			case EAlgorithm::hs384: Verifier = Verifier.allow_algorithm(jwt::algorithm::hs384{ TCHAR_TO_ANSI(*Key) }); break;
			case EAlgorithm::hs512: Verifier = Verifier.allow_algorithm(jwt::algorithm::hs256{ TCHAR_TO_ANSI(*Key) }); break;
			case EAlgorithm::rs256: Verifier = Verifier.allow_algorithm(jwt::algorithm::rs256(TCHAR_TO_ANSI(*Key), "", "", "")); break;
			case EAlgorithm::rs384: Verifier = Verifier.allow_algorithm(jwt::algorithm::rs384(TCHAR_TO_ANSI(*Key), "", "", "")); break;
			case EAlgorithm::rs512: Verifier = Verifier.allow_algorithm(jwt::algorithm::rs512(TCHAR_TO_ANSI(*Key), "", "", "")); break;
			/*case Algorithm::ed25519:Verifier = Verifier.allow_algorithm(jwt::algorithm::ed25519{ TCHAR_TO_ANSI(*key) }); break;
			case Algorithm::ed448:Verifier = Verifier.allow_algorithm(jwt::algorithm::ed448{ TCHAR_TO_ANSI(*key) }); break;
			case Algorithm::es256:Verifier = Verifier.allow_algorithm(jwt::algorithm::es256{ TCHAR_TO_ANSI(*key) }); break;
			case Algorithm::es384:Verifier = Verifier.allow_algorithm(jwt::algorithm::es384{ TCHAR_TO_ANSI(*key) }); break;
			case Algorithm::es512:Verifier = Verifier.allow_algorithm(jwt::algorithm::es512{ TCHAR_TO_ANSI(*key) }); break;
			case Algorithm::ps256:Verifier = Verifier.allow_algorithm(jwt::algorithm::hs512{ TCHAR_TO_ANSI(*key) }); break;
			case Algorithm::ps384:Verifier = Verifier.allow_algorithm(jwt::algorithm::ps384{ TCHAR_TO_ANSI(*key) }); break;
			case Algorithm::ps512:Verifier = Verifier.allow_algorithm(jwt::algorithm::ps512{ TCHAR_TO_ANSI(*key) }); break;*/
		}	
	} catch(...) {}
}

bool UJWTVerifier::VerifyJWT(const FString& Input) {
	try {
		 Verifier.verify(jwt::decode(TCHAR_TO_ANSI(*Input)));
	}
	catch (const std::exception& ec) {
		UE_LOG(LogTemp, Error, TEXT("Error:  %d"), *ec.what());
		return false;
	}
	
	return true;
}

void UJWTVerifier::WithIssuer(const FString& Issuer) {
	Verifier = Verifier.with_issuer(TCHAR_TO_ANSI(*Issuer));
}

void UJWTVerifier::SetLeeway(int32 Leeway) {
	Verifier = Verifier.leeway(Leeway);
}

void UJWTVerifier::WithAudience(const FString& Audience) {
	Verifier = Verifier.with_audience(TCHAR_TO_ANSI(*Audience));
}

void UJWTVerifier::WithSubject(const FString& Subject) {
	Verifier = Verifier.with_subject(TCHAR_TO_ANSI(*Subject));
}

void UJWTVerifier::WithID(const FString& ID) {
	Verifier = Verifier.with_id(TCHAR_TO_ANSI(*ID));
}

void UJWTVerifier::WithCustomClaim(const FString& Name, const FString& Value) {
	Verifier = Verifier.with_custom_claim(TCHAR_TO_ANSI(*Name), TCHAR_TO_ANSI(*Value));
}