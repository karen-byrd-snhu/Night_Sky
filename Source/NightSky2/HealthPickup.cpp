// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"
#include "NightSky2Character.h"


AHealthPickup::AHealthPickup()
{
	HealingAmount = 20.f;
}

void AHealthPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("AHealthPickup::OverlapBegin"));
	ANightSky2Character* NightSky2Character = Cast<ANightSky2Character>(OtherActor);
	if (NightSky2Character)
	{
		NightSky2Character->SetHealth(NightSky2Character->GetHealth() + HealingAmount);
	}

	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}
