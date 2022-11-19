// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponComponent::AttachToPlayer(APlayerChar* target) {
	selfActor = target;
	if (selfActor) {
		UE_LOG(LogTemp, Warning, TEXT("attach"));
		FAttachmentTransformRules rules(EAttachmentRule::SnapToTarget, true);
		GetOwner()->AttachToComponent(selfActor->GetWeaponPoint(), rules, TEXT("WeaponPoint"));

		selfActor->evOnUseItem.AddDynamic(this, &UWeaponComponent::Fire);
	}
}

void UWeaponComponent::Fire() {
	if (!selfActor || !selfActor->GetController())
		return;

	UE_LOG(LogTemp, Warning, TEXT("pium"));

}

