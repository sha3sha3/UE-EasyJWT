// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.

#pragma once

#include "Modules/ModuleManager.h"
#include "JwtGenerator.h"
#include "JwtVerifier.h"

class EASYJWT_API FEasyJwtModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	FORCEINLINE TSharedPtr<FJwtGeneratorModule> GetGenerator() const {
		return JwtGenerator;
	}

	FORCEINLINE TSharedPtr<FJwtVerifierModule> GetVerifier() const {
		return JwtVerifier;
	}

	static FEasyJwtModule& Get();
private:
	TSharedPtr<FJwtGeneratorModule> JwtGenerator = nullptr;
	TSharedPtr<FJwtVerifierModule> JwtVerifier = nullptr;

	static FEasyJwtModule* EasyJwt;
};
