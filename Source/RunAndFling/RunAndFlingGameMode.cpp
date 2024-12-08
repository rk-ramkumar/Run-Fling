// Copyright Epic Games, Inc. All Rights Reserved.

#include "RunAndFlingGameMode.h"
#include "RunAndFlingCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARunAndFlingGameMode::ARunAndFlingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
