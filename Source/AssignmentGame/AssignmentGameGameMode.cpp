// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssignmentGameGameMode.h"
#include "AssignmentGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AAssignmentGameGameMode::AAssignmentGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AAssignmentGameGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);
}

void AAssignmentGameGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> widget)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (widget != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), widget);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}
