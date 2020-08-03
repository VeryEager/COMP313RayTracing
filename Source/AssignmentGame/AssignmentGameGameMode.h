// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AssignmentGameGameMode.generated.h"

UCLASS(minimalapi)
class AAssignmentGameGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
	AAssignmentGameGameMode();
    UFUNCTION(BlueprintCallable, Category = "UI")
    void ChangeMenuWidget(TSubclassOf<UUserWidget> widget);


protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
    TSubclassOf<UUserWidget> StartingWidgetClass;

    UPROPERTY()
    UUserWidget* CurrentWidget;
};



