// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchBox.h"

// Sets default values
ASwitchBox::ASwitchBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	SetRootComponent(Scene);
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh->SetRelativeTransform(FTransform::Identity);

	StaticMesh->SetCollisionProfileName("OverlapAllDynamic");

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ASwitchBox::OnBeginOverlap);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &ASwitchBox::OnEndOverlap);
}

// Called when the game starts or when spawned
void ASwitchBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitchBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASwitchBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("SwitchBox BeginOverlap!!!"));

	if (m_Dele_Play.IsBound())
		m_Dele_Play.Broadcast(true);
}

void ASwitchBox::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("SwitchBox EndOverlap!!!"));

	if (m_Dele_Play.IsBound())
		m_Dele_Play.Broadcast(false);
}

