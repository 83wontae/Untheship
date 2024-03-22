// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnArea.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawnArea::ASpawnArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	SetRootComponent(Scene);
	Box->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASpawnArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnArea::DoSpawn()
{
	FVector RandVec = UKismetMathLibrary::RandomPointInBoundingBox(Box->GetComponentLocation(), Box->GetScaledBoxExtent());

	AActor* actor = GetWorld()->SpawnActor<AActor>(SpawnClass, FTransform(FRotator(0, 0, 0), RandVec, FVector(0.5, 0.5, 0.5)));
}

