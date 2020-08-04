// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleFlowerActor.h"

// Sets default values
ACollectibleFlowerActor::ACollectibleFlowerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AccumulatedScore = 1;

	StaticComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FlowerMeshAsset(TEXT("StaticMesh'/Game/Content/Meadow_Environment_Set/Environment/Foliage/Meshes/SM_flower_common_poppy_02'"));
	if (FlowerMeshAsset.Object)
	{
		StaticComponent->SetStaticMesh(FlowerMeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void ACollectibleFlowerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectibleFlowerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rotation = GetActorRotation();
	float RotDegree = DeltaTime * 10.0f;
	Rotation.Yaw += RotDegree;

	SetActorLocationAndRotation(GetActorLocation(), Rotation);
}

