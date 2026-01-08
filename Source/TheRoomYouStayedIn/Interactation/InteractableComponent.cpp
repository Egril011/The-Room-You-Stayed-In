// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableComponent.h"
#include "InteractableInterface.h"

// Sets default values for this component's properties
UInteractableComponent::UInteractableComponent()
{
}

void UInteractableComponent::Interact(AActor* Actor)
{
	if (!IsValid(Actor) || !IsValid(GetWorld()))
		return;
	
	//Process the LineTrace
	const FVector StartLocation = Actor->GetActorLocation();
	const FVector EndLocation = StartLocation + (Actor->GetActorRotation().Vector() * LinetraceDistance);
	
	FHitResult HitResult;
	
	const bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
		);
	
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1);
	
	if (bHit)
	{
		//Looking if the Actor hit implement the interface
		AActor* HitActor = HitResult.GetActor();
		if (!IsValid(HitActor))
			return;
		
		if (HitActor->Implements<UInteractableInterface>())
		{
			IInteractableInterface::Execute_Interact(HitActor, Actor);
		}
	}
}  