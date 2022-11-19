// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "PlayerChar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUseItem);

UCLASS()
class P3_SHOOTER_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlayerVals)
		UCameraComponent* cam = nullptr;

	UPROPERTY(EditAnywhere, Category = PlayerVals)
		float moveSpeed = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlayerVals)
		UStaticMeshComponent* hingeMesh;

	UPROPERTY(BlueprintAssignable, Category = PlayerVals)
		FOnUseItem evOnUseItem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float vel);
	void MoveRight(float vel);
	void OnUseItem();

public:
	UStaticMeshComponent* GetWeaponPoint() const { return hingeMesh; };
	UCameraComponent* GetCam() const { return cam; };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
