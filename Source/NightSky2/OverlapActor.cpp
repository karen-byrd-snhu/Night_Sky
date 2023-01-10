// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlapActor.h"
#include "Components/StaticMeshComponent.h" // suing preset files from UE4 for static mesh component
#include "Components/BoxComponent.h"  // using preset files from UE$ for box component


// Sets default values
AOverlapActor::AOverlapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// creating basis classes
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	SetRootComponent(PickupMesh);

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
	OverlapBox->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AOverlapActor::BeginPlay()
{
	Super::BeginPlay();

	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &AOverlapActor::BeginOverlap);
	OverlapBox->OnComponentEndOverlap.AddDynamic(this, &AOverlapActor::EndOverlap);

	PickupMesh->OnComponentHit.AddDynamic(this, &AOverlapActor::ComponentHit);
	
}

// Called every frame
void AOverlapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOverlapActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
}

void AOverlapActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("EndOverlap"));
}

void AOverlapActor::ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpluse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("ComponentHit"));
}

