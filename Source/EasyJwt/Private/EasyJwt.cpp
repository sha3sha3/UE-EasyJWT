// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

#include "EasyJwt.h"

#define LOCTEXT_NAMESPACE "FEasyJwtModule"

FEasyJwtModule* FEasyJwtModule::EasyJwt = nullptr;

void FEasyJwtModule::StartupModule()
{
	if (!EasyJwt)
		EasyJwt = this;
	else
		return;
	if (!JwtGenerator) {
		FModuleManager::LoadModuleChecked<FJwtGeneratorModule>("JwtGenerator");
		JwtGenerator = MakeShared<FJwtGeneratorModule>(FJwtGeneratorModule::Get());
	}
	if (!JwtVerifier) {
		FModuleManager::LoadModuleChecked<FJwtVerifierModule>("JwtVerifier");
		JwtVerifier = MakeShared <FJwtVerifierModule>(FJwtVerifierModule::Get());
	}
}

void FEasyJwtModule::ShutdownModule()
{

	
}

FEasyJwtModule& FEasyJwtModule::Get()
{
	if (EasyJwt == nullptr)
	{
		check(IsInGameThread());
		FModuleManager::LoadModuleChecked<FEasyJwtModule>("FEasyJwtModule");
	}
	check(EasyJwt);

	return *EasyJwt;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEasyJwtModule, EasyJwt)