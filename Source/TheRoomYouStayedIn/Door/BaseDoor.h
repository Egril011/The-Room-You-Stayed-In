// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactation/InteractableInterface.h"
#include "BaseDoor.generated.h"

class UTimelineComponent;

UCLASS()
class THEROOMYOUSTAYEDIN_API ABaseDoor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//The door's StaticMesh
	UPROPERTY(EditAnywhere, Category="Door")
	TObjectPtr<UStaticMeshComponent> DoorStaticMeshComponent;

private:
	/*The variables for the door animation*/
	UPROPERTY(EditAnywhere, Category="Door|Animation")
	TObjectPtr<UCurveFloat> DoorCurveFloatAnimation;
	
	UPROPERTY(EditAnywhere, Category="Door|Animation")
	TObjectPtr<UTimelineComponent> DoorTimelineComponent;
	
	UPROPERTY(EditAnywhere, Category="Door|Animation")
	TObjectPtr<USceneComponent> DoorSceneComponentAnimation;
	
	/*The variables*/
	bool bIsDoorOpen = false;
	FVector DoorSceneLocation;
	FRotator DoorSceneRotation;
	FVector DoorLocation;
	FRotator DoorRotation;
	
	//The animation to open or close the door
	void OpenCloseDoor();
	UFUNCTION()
	void TickOpenCloseDoor(float Value);
	
	//Interface
	virtual void Interact_Implementation(AActor* Interactor) override;
};
