// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerGame.h"

#include "Kismet/GameplayStatics.h"

void APlayerControllerGame::OnPossess(APawn* InPawn)
{
	//Find into the world the starting camera 
	Super::OnPossess(InPawn);
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("StartingCamera"), FoundActors);

	if (FoundActors.Num() > 0)
	{
		SetViewTarget(FoundActors[0]);
	}
}