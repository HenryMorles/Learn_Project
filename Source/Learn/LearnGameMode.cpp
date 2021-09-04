// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearnGameMode.h"
#include "LearnCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALearnGameMode::ALearnGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
