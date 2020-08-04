// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ScoredPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTGAME_API AScoredPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AScoredPlayerState();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scoring")
	int PlayerScore;
};
