// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnBox.h"
#include "SpawnArea.h"

// Sets default values
ASpawnBox::ASpawnBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	SetRootComponent(Scene);
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh->SetRelativeTransform(FTransform::Identity);

	StaticMesh->SetCollisionProfileName("OverlapAllDynamic");

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ASpawnBox::OnBeginOverlap);
}

// Called when the game starts or when spawned
void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("SpawnBox BeginOverlap!!!"));

	for (int i = 0; i < 5; ++i)
	{
		SpawnArea->DoSpawn();
	}
}

