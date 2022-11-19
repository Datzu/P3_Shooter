// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerChar.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class P3_SHOOTER_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	APlayerChar* selfActor;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector shootPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Proyectile)
		bool bUseRayCast;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Proyectile)
		float shootSpeed;

public:
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void AttachToPlayer(APlayerChar* target);

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void Fire();

};
