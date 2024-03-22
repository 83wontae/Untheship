// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwitchBox.generated.h"

// DECLARE_DELEGATE : 한개만 바인드 가능
// DECLARE_MULTICAST_DELEGATE : 여러개 바인드 가능
// DECLARE_DYNAMIC_DELEGATE : 블루프린트에서 바인드 가능, 한개만 바인드 가능
// DECLARE_DYNAMIC_MULTICAST_DELEGATE: 블루프린트에서 바인드 가능, 여러개 바인드 가능

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
