// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NoteCombWidget.generated.h"

UCLASS()
class PROJECTRG_API UNoteCombWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	void RefreshNoteCombText(FText Text, FLinearColor TextColor);

protected:
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UTextBlock* NoteCombText;
};
