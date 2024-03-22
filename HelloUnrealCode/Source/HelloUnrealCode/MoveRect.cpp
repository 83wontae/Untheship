// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveRect.h"
#include "Components/BoxComponent.h"
#include "SwitchBox.h"

// Sets default values
AMoveRect::AMoveRect():m_MoveType(EN_MoveType::Right), m_LocX(0), m_LocZ(0), m_IsPlay(false)
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
void AMoveRect::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != m_SwitchBox)
		m_SwitchBox->m_Dele_Play.AddDynamic(this, &AMoveRect::Event_Dele_Overlap);
}

// Called every frame
void AMoveRect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (false == m_IsPlay)
		return;

	switch (m_MoveType)
	{
	case EN_MoveType::Right:
		m_LocX += 1;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, m_LocZ));

		if (StaticMesh->GetRelativeLocation().X > 200)
		{
			m_MoveType = EN_MoveType::Up;
		}

		break;
	case EN_MoveType::Up:
		m_LocZ += 1;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, m_LocZ));

		if (StaticMesh->GetRelativeLocation().Z > 200)
		{
			m_MoveType = EN_MoveType::Left;
		}

		break;
	case EN_MoveType::Left:
		m_LocX -= 1;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, m_LocZ));

		if (StaticMesh->GetRelativeLocation().X < 0)
		{
			m_MoveType = EN_MoveType::Down;
		}

		break;
	case EN_MoveType::Down:
		m_LocZ -= 1;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, m_LocZ));

		if (StaticMesh->GetRelativeLocation().Z < 0)
		{
			m_MoveType = EN_MoveType::Right;
		}

		break;
	default:
		break;
	}
}

void AMoveRect::EventBeginOverlap_Implementation()
{
	m_IsPlay = true;
}

void AMoveRect::EventEndOverlap_Implementation()
{
	m_IsPlay = false;
}

void AMoveRect::Event_Dele_Overlap(bool IsPlay)
{
	m_IsPlay = IsPlay;
}

