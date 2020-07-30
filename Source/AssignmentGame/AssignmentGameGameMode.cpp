// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssignmentGameGameMode.h"
#include "AssignmentGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAssignmentGameGameMode::AAssignmentGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
