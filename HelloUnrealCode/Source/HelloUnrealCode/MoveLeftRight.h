// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EventInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveLeftRight.generated.h"

UCLASS()
class HELLOUNREALCODE_API AMoveLeftRight : public AActor, public IEventInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight();

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

	bool IsRight;

	float Location_X;

	bool m_IsPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ASwitchBox* m_SwitchBox;
};
