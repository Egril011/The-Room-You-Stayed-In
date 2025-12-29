// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraTrigger.h"

#include "TheRoomYouStayedInCharacter.h"
#include "FixedCamera.h"

ACameraTrigger::ACameraTrigger()
{
	
}

void ACameraTrigger::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACameraTrigger::OnOverlapBegin);
}

void ACameraTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (!IsValid(OtherActor) || OtherActor == this)
		return;
	
	if (OtherActor->IsA<ATheRoomYouStayedInCharacter>())
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(GetWorld()->GetFirstPlayerController()))
		{
			PlayerController->SetViewTargetWithBlend(Camera, CameraSwitchSpeed);
		}
	}
}