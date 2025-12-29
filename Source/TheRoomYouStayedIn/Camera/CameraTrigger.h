// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "CameraTrigger.generated.h"

class UBoxComponent;
class AFixedCamera;
/**
 * 
 */
UCLASS()
class THEROOMYOUSTAYEDIN_API ACameraTrigger : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	ACameraTrigger();
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

private:
	//The camera
	UPROPERTY(EditAnywhere, Category="Camera", meta=(AllowPrivateAccess=true))
	TObjectPtr<AFixedCamera> Camera;
	
	//The camera's speed when it is switched
	UPROPERTY(EditAnywhere, Category="Camera", meta=(AllowPrivateAccess=true))
	float CameraSwitchSpeed = 0.75f;
};