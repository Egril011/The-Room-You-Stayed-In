// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NotificationWidget.generated.h"

/**
 * 
 */
UCLASS()
class THEROOMYOUSTAYEDIN_API UNotificationWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetText(const FText& Text);	
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextBlock;
};
