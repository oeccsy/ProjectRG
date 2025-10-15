// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/NoteCombWidget.h"
#include "Components/TextBlock.h"

void UNoteCombWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UNoteCombWidget::RefreshNoteCombText(FText Text, FLinearColor TextColor)
{
	if (NoteCombText == nullptr) return;

	NoteCombText->SetText(Text);
	NoteCombText->SetColorAndOpacity(FSlateColor(TextColor));
}