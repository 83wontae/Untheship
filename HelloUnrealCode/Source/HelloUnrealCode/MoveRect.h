// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EventInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveRect.generated.h"

UENUM(BlueprintType)
enum class EN_MoveType : uint8
{
	Right UMETA(DisplayName = "Right"),
	Up UMETA(DisplayName = "Up"),
	Left UMETA(DisplayName = "Left"),
	Down UMETA(DisplayName = "Down"),
};

UCLASS()
class HELLOUNREALCODE_API AMoveRect : public AActor, public IEventInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveRect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EventBeginOverlap();

	virtual void EventBeginOverlap_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EventEndOverlap();

	virtual void EventEndOverlap_Implementation() override;

	UFUNCTION()
	void Event_Dele_Overlap(bool IsPlay);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	EN_MoveType m_MoveType;

	int m_LocX;
	int m_LocZ;

	bool m_IsPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ASwitchBox* m_SwitchBox;
};
