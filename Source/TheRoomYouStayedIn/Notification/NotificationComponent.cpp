// Fill out your copyright notice in the Description page of Project Settings.


#include "Notification/NotificationComponent.h"

#include "Widget/NotificationWidget.h"

// Sets default values for this component's properties
UNotificationComponent::UNotificationComponent()
{
}

void UNotificationComponent::ShowWidget(const FText& Text, const float Timer)
{
	//Process to show the widget
	if (!IsValid(GetWorld()) || !IsValid(NotificationWidget))
		return;
	
	if (!IsValid(WidgetRef))
	{
		WidgetRef = CreateWidget<UNotificationWidget>(GetWorld()->GetFirstPlayerController(), 
			NotificationWidget);
	}
	
	if (!IsValid(WidgetRef))
		return;
	
	WidgetRef->SetText(Text);
	
	//Start the timer to clear the widget
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandleNotification, 
		this,
		&UNotificationComponent::RemoveWidget,
		Timer, 
		false
		);
}

void UNotificationComponent::RemoveWidget()
{
	if (!IsValid(WidgetRef) || !IsValid(GetWorld()))
		return;
	
	GetWorld()->GetTimerManager().ClearTimer(TimerHandleNotification);
	WidgetRef->RemoveFromParent();
	WidgetRef = nullptr;
}