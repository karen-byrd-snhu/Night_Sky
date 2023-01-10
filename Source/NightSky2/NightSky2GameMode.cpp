// Copyright Epic Games, Inc. All Rights Reserved.

#include "NightSky2GameMode.h"
#include "NightSky2HUD.h"
#include "NightSky2Character.h"
#include "UObject/ConstructorHelpers.h"

ANightSky2GameMode::ANightSky2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("Class'/Script/NightSky2.PawnCharacter'"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ANightSky2HUD::StaticClass();
}
