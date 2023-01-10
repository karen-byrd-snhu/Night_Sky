// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class NIGHTSKY2_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// overlapping sphere
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Collision")
		class USphereComponent* CollisionVolume;

	// base mesh component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Mesh")
		class UStaticMeshComponent* Mesh;

	// toggles on/off rotating
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | ItemProperties")
		bool bRotate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | ItemProperties")
		float RotationRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
