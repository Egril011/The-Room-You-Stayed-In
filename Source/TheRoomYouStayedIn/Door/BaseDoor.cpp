// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDoor.h"
#include "TheRoomYouStayedInCharacter.h"
#include "Components/TimelineComponent.h"

// Sets default values
ABaseDoor::ABaseDoor()
{
	DoorStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("DoorStaticMeshComponent");
	RootComponent = DoorStaticMeshComponent;
	
	DoorSceneComponentAnimation = CreateDefaultSubobject<USceneComponent>("DoorSceneComponentAnimationLocation");
	DoorSceneComponentAnimation->SetupAttachment(RootComponent);
	
	DoorTimelineComponent = CreateDefaultSubobject<UTimelineComponent>("DoorTimelineComponent");
}

// Called when the game starts or when spawned
void ABaseDoor::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(DoorTimelineComponent) && IsValid(DoorCurveFloatAnimation))
	{
		FOnTimelineFloat TimelineFunction;
		TimelineFunction.BindUFunction(this, "TickOpenCloseDoor");
		
		DoorTimelineComponent->AddInterpFloat(DoorCurveFloatAnimation, TimelineFunction);
		DoorTimelineComponent->SetLooping(false);
	}
	
	//Save the location and rotation of DoorScene and the door
	DoorSceneLocation = DoorSceneComponentAnimation->GetComponentLocation();
	DoorSceneRotation = DoorSceneComponentAnimation->GetComponentRotation();
	DoorLocation = GetActorLocation();
	DoorRotation = GetActorRotation();
}

void ABaseDoor::OpenCloseDoor()
{UE_LOG(LogTemp, Warning, TEXT("TEst"));
	if (!IsValid(DoorCurveFloatAnimation) || !IsValid(DoorTimelineComponent))
		return;
	UE_LOG(LogTemp, Warning, TEXT("TEst1"));
	//If the door is already opened play the close animation
	if (!bIsDoorOpen)
	{
		UE_LOG(LogTemp, Warning, TEXT("TEst2"));
		DoorTimelineComponent->Play();	
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("TEst3"));
	DoorTimelineComponent->ReverseFromEnd();
}

void ABaseDoor::TickOpenCloseDoor(float Value)
{
	FVector NewDoorLocation = FMath::Lerp(DoorLocation, DoorSceneLocation, Value);
	FRotator NewRotator = FMath::Lerp(DoorRotation, DoorSceneRotation, Value);
	SetActorLocation(NewDoorLocation);
	SetActorRotation(NewRotator);
	
	if (Value >= 1.f)
	{
		bIsDoorOpen = true;
	}
	else if (Value <= 0.f)
	{
		bIsDoorOpen = false;
	}
}

void ABaseDoor::Interact_Implementation(AActor* Interactor)
{
	//Play the animation if the player interacts with the door
	if (Interactor->IsA<ATheRoomYouStayedInCharacter>())
	{
		OpenCloseDoor();
	}
}