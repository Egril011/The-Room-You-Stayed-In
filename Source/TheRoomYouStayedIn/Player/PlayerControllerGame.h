// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TheRoomYouStayedInPlayerController.h"
#include "PlayerControllerGame.generated.h"

class AFixedCamera;
/**
 * 
 */
UCLASS()
class THEROOMYOUSTAYEDIN_API APlayerControllerGame : public ATheRoomYouStayedInPlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void OnPossess(APawn* InPawn) override;
};
