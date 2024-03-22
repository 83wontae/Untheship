// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnArea.generated.h"

UCLASS()
class HELLOUNREALCODE_API ASpawnArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void DoSpawn();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* Box;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> SpawnClass;
};
