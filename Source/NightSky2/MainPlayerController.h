// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTSKY2_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// reference to the UMG assest in the editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget>HUDOverlayAsset;

	// variable to hold the widget after creation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* HUDOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget>WPauseMenu;

	UPROPERTY(Visibleanywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* PauseMenu;

	bool bPauseMenuVisible;
	
protected:
	virtual void BeginPlay() override;
};
