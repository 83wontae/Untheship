// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeViewer.h"
#include "Components/TextRenderComponent.h"
#include "SwitchBox.h"

// Sets default values
ATimeViewer::ATimeViewer():m_IsPlay(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender"));

	SetRootComponent(Scene);
	TextRender->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
	TextRender->SetRelativeTransform(FTransform::Identity);

	TextRender->SetHorizontalAlignment(EHTA_Center);
	TextRender->SetVerticalAlignment(EVRTA_TextCenter);
}

// Called when the game starts or when spawned
void ATimeViewer::BeginPlay()
{
	Super::BeginPlay();
	
	if (nullptr != m_SwitchBox)
		m_SwitchBox->m_Dele_Play.AddDynamic(this, &ATimeViewer::Event_Dele_Overlap);
}

// Called every frame
void ATimeViewer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (false == m_IsPlay)
		return;

	FString strMin, strSec, strTime;

	m_DeltaSeconds += DeltaTime;
	strMin = FloatToReturnStr00(m_DeltaSeconds / 60);
	strSec = FloatToReturnStr00(FMath::Fmod(m_DeltaSeconds, 60));
	strTime = strMin + ":" + strSec;
	TextRender->SetText(FText::FromString(strTime));
}

void ATimeViewer::EventBeginOverlap_Implementation()
{
	m_IsPlay = true;
}

void ATimeViewer::EventEndOverlap_Implementation()
{
	m_IsPlay = false;
}

void ATimeViewer::Event_Dele_Overlap(bool IsPlay)
{
	m_IsPlay = IsPlay;
}

FString ATimeViewer::FloatToReturnStr00(float Number)
{
	FString strResult = "";
	int32 nNum = FMath::FloorToInt(Number);
	strResult = FString::Printf(TEXT("%d"), nNum);

	if (nNum < 10)
	{
		strResult = FString::Printf(TEXT("0%d"), nNum);
	}

	return strResult;
}

