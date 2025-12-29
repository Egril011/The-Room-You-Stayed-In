// Fill out your copyright notice in the Description page of Project Settings.


#include "FixedCamera.h"
#include "Camera/CameraComponent.h"

// Sets default values
AFixedCamera::AFixedCamera()
{
	FixedCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	RootComponent = FixedCamera;
}

void AFixedCamera::BeginPlay()
{
	Super::BeginPlay();
}