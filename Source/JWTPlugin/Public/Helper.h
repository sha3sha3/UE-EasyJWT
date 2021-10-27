//ForeFront electronics 2021
#pragma once
#include "Engine/Engine.h"
#include"Helper.generated.h"

UENUM(BlueprintType)
enum class EAlgorithm : uint8
{
	/*the rest of algorithms to come on future updates*/
	//ecdsa UMETA(DisplayName = "ECDSA"),
	hs256 UMETA(DisplayName = "HS256"),
	hs384 UMETA(DisplayName = "HS348"),
	hs512 UMETA(DisplayName = "HS512"),
	rs256 UMETA(DisplayName = "RS256"),
	rs384 UMETA(DisplayName = "RS384"),
	rs512 UMETA(DisplayName = "RS512"),
	/*es256 UMETA(DisplayName = "ES256"),
	es384 UMETA(DisplayName = "ES384"),
	es512 UMETA(DisplayName = "ES512"),
	ed25519 UMETA(DisplayName = "ED25519"),
	ed448 UMETA(DisplayName = "ED448"),
	ps256 UMETA(DisplayName = "PS256"),
	ps384 UMETA(DisplayName = "PS384"),
	ps512 UMETA(DisplayName = "PS512")*/
};
