// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwitchBox.generated.h"

// DECLARE_DELEGATE : �Ѱ��� ���ε� ����
// DECLARE_MULTICAST_DELEGATE : ������ ���ε� ����
// DECLARE_DYNAMIC_DELEGATE : �������Ʈ���� ���ε� ����, �Ѱ��� ���ε� ����
// DECLARE_DYNAMIC_MULTICAST_DELEGATE: �������Ʈ���� ���ε� ����, ������ ���ε� ����

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_Play, bool, IsPlay);

UCLASS()
class HELLOUNREALCODE_API ASwitchBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitchBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_Play m_Dele_Play;
};
