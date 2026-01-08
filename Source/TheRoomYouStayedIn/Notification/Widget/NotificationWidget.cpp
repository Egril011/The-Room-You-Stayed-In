// Fill out your copyright notice in the Description page of Project Settings.


#include "NotificationWidget.h"

#include "Components/TextBlock.h"

void UNotificationWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetIsEnabled(true);
}

void UNotificationWidget::SetText(const FText& Text)
{
	TextBlock->SetText(Text);
}