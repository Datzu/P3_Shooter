// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpComponent.h"

// Sets default values for this component's properties
UPickUpComponent::UPickUpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UPickUpComponent::OnSphereBeginOverlap);
	// UE_LOG(LogTemp, Warning, TEXT("start"));

}

void UPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	// UE_LOG(LogTemp, Warning, TEXT("start overlapp"));

	APlayerChar* player = Cast<APlayerChar>(OtherActor);
	if (player) {
		evOnPickUp.Broadcast(player);
		OnComponentBeginOverlap.RemoveAll(this);
		// UE_LOG(LogTemp, Warning, TEXT("get it"));
	}

}



