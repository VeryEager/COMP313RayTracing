// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomBlueprintNode.generated.h"

UCLASS()
class ASSIGNMENTGAME_API UCustomBlueprintNode : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure)
	static float EuclideanDistance(const FVector start, const FVector end);
};
