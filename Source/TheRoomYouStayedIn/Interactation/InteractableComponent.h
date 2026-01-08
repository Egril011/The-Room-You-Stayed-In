// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEROOMYOUSTAYEDIN_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableComponent();
	
	//To interact with an object
	void Interact(AActor* Actor);

protected:
	UPROPERTY(EditAnywhere, Category="InteractableComponent|Variables")
	float LinetraceDistance = 500.f;
};
