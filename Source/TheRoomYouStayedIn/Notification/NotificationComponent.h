// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NotificationComponent.generated.h"


class UNotificationWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEROOMYOUSTAYEDIN_API UNotificationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNotificationComponent();
	
	void ShowWidget(const FText& Text, const float Timer);

protected:
	//The widget to show
	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UNotificationWidget> NotificationWidget;
	
	//A ref to the widget
	UPROPERTY()
	TObjectPtr<UNotificationWidget> WidgetRef;
	
private:
	FTimerHandle TimerHandleNotification;
	
	UFUNCTION()
	void RemoveWidget();
};
