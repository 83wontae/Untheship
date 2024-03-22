// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"
#include "SwitchBox.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight():IsRight(true), Location_X(0), m_IsPlay(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	SetRootComponent(Scene);
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh->SetRelativeTransform(FTransform::Identity);
}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();
	
	if(nullptr != m_SwitchBox)
		m_SwitchBox->m_Dele_Play.AddDynamic(this, &AMoveLeftRight::Event_Dele_Overlap);
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (false == m_IsPlay)
		return;

	if (IsRight)
	{
		Location_X++;
		StaticMesh->SetRelativeLocation(FVector(Location_X, 0, 0));

		if (StaticMesh->GetRelativeLocation().X > 200)
		{
			IsRight = false;
		}
	}
	else
	{
		Location_X--;
		StaticMesh->SetRelativeLocation(FVector(Location_X, 0, 0));

		if (StaticMesh->GetRelativeLocation().X < 0)
		{
			IsRight = true;
		}
	}
}

void AMoveLeftRight::EventBeginOverlap_Implementation()
{
	m_IsPlay = true;
}

void AMoveLeftRight::EventEndOverlap_Implementation()
{
	m_IsPlay = false;
}

void AMoveLeftRight::Event_Dele_Overlap(bool IsPlay)
{
	m_IsPlay = IsPlay;
}

