// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EventInterface.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)
class HELLOUNREALCODE_API UEventInterface : public UInterface
{
	GENERATED_BODY()
	
};

class HELLOUNREALCODE_API IEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EventBeginOverlap();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EventEndOverlap();

};
