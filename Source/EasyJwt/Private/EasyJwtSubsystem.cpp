// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

#include "EasyJwtSubsystem.h"




void UEasyJwtSubsystem::Deinitialize()
{

}

void UEasyJwtSubsystem::InitVerifier(const FString& Key, EVerifierAlgorithm Algorithm)
{
	if (EasyJwt->GetVerifier())
		EasyJwt->GetVerifier()->InitVerifier(Key, Algorithm);
}


void UEasyJwtSubsystem::WithIssuer(const FString& Issuer)
{
	if (EasyJwt->GetVerifier())
		EasyJwt->GetVerifier()->WithIssuer(Issuer);
}

void UEasyJwtSubsystem::WithSubject(const FString& Subject)
{
	if (EasyJwt->GetVerifier())
		EasyJwt->GetVerifier()->WithSubject(Subject);
}

void UEasyJwtSubsystem::WithAudience(const FString& Audience)
{
	if (EasyJwt->GetVerifier())
		EasyJwt->GetVerifier()->WithAudience(Audience);
}

void UEasyJwtSubsystem::SetLeeway(int32 Leeway)
{
	if (EasyJwt->GetVerifier())
		EasyJwt->GetVerifier()->SetLeeway(Leeway);
}

void UEasyJwtSubsystem::WithID(const FString& ID)
{
	if (EasyJwt->GetVerifier())
		EasyJwt->GetVerifier()->WithID(ID);
}

void UEasyJwtSubsystem::WithCustomClaim(const FString& Name, const FString& Value)
{
	if (EasyJwt->GetVerifier())
		EasyJwt->GetVerifier()->WithCustomClaim(Name, Value);
}

bool UEasyJwtSubsystem::VerifyJWT(const FString& Input)
{
	if (EasyJwt->GetVerifier())
		return EasyJwt->GetVerifier()->VerifyJWT(Input);
	
	return false;
}

TMap<FString, FString> UEasyJwtSubsystem::GetClaims(const FString& JWTToken)
{
	if (EasyJwt->GetVerifier())
		return	EasyJwt->GetVerifier()->GetClaims(JWTToken);

	return TMap<FString, FString>();
}

void UEasyJwtSubsystem::InitGenerator(const FString& Key, EGeneratorAlgorithm Algorithm)
{
	if (EasyJwt->GetGenerator())
		EasyJwt->GetGenerator()->InitGenerator(Key, Algorithm);
}

void UEasyJwtSubsystem::SetType(const FString& Type)
{
	if (EasyJwt->GetGenerator())
		EasyJwt->GetGenerator()->SetType(Type);
}

void UEasyJwtSubsystem::SetContentType(const FString& ContentType)
{
	if (EasyJwt->GetGenerator())
		EasyJwt->GetGenerator()->SetContentType(ContentType);
}

void UEasyJwtSubsystem::SetKeyID(const FString& KeyID)
{
	if (EasyJwt->GetGenerator())
		EasyJwt->GetGenerator()->SetKeyID(KeyID);
}

void UEasyJwtSubsystem::SetSubject(const FString& Subject)
{
	if (EasyJwt->GetGenerator())
		EasyJwt->GetGenerator()->SetSubject(Subject);
}

void UEasyJwtSubsystem::SetAudience(const FString& Audience)
{
	if (EasyJwt->GetGenerator())
		EasyJwt->GetGenerator()->SetAudience(Audience);
}

void UEasyJwtSubsystem::SetID(const FString& ID)
{
	if (EasyJwt->GetGenerator())
		EasyJwt->GetGenerator()->SetID(ID);
}

FString UEasyJwtSubsystem::GenerateJwtToken(bool IATClaim, TMap<FString, FString> Claims, TMap<FString, FString> HeaderClaims, int NotBeforeSec, int ExpireAfterSec)
{
	if (EasyJwt->GetGenerator())
		return EasyJwt->GetGenerator()->GenerateJwtToken(IATClaim, NotBeforeSec, ExpireAfterSec, Claims, HeaderClaims);

	return "";
}

TSharedPtr<FEasyJwtModule> UEasyJwtSubsystem::GetEasyJwt()
{
	if (!EasyJwt)
		EasyJwt = MakeShared<FEasyJwtModule>(FEasyJwtModule::Get());

	return EasyJwt;
}

void UEasyJwtSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	FModuleManager::LoadModuleChecked<FEasyJwtModule>("EasyJwt");
	EasyJwt = MakeShared<FEasyJwtModule>(FEasyJwtModule::Get());
}
