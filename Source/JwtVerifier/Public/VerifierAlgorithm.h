// Copyright (c) 2021-2023 MrShaaban, Mohamad Shaaban, https://github.com/sha3sha3/UE-EasyJWT.
#pragma once
#include "Engine/Engine.h"
#include "VerifierAlgorithm.generated.h"

UENUM(BlueprintType)
enum class EVerifierAlgorithm : uint8
{
	/*the rest of algorithms to come on future updates*/
	HS256 UMETA(DisplayName = "HS256"),
	HS384 UMETA(DisplayName = "HS348"),
	HS512 UMETA(DisplayName = "HS512"),
	RS256 UMETA(DisplayName = "RS256"),
	RS384 UMETA(DisplayName = "RS384"),
	RS512 UMETA(DisplayName = "RS512")
};
