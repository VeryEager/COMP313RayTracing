// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomBlueprintNode.h"


float UCustomBlueprintNode::EuclideanDistance(const FVector start, const FVector end) {
	float formula = FMath::Square(end.X - start.X) + FMath::Square(end.Y - start.Y) + FMath::Square(end.Z - start.Z);
	return FGenericPlatformMath::Sqrt(formula);
}

