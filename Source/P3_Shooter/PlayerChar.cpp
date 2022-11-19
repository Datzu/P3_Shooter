// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChar.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCam"));
	cam->SetupAttachment(GetCapsuleComponent());
	cam->bUsePawnControlRotation = true;

	hingeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HingeWeapon"));
	hingeMesh->SetupAttachment(cam);
	hingeMesh->bCastDynamicShadow = true;
	hingeMesh->CastShadow = false;
	//hingeMesh->SetRelativeLocation(FVector())
	hingeMesh->SetOnlyOwnerSee(true);

	UCharacterMovementComponent* cmove = GetCharacterMovement();
	cmove->BrakingFriction = 10.f;
	cmove->MaxAcceleration = 10000.f;
	cmove->MaxWalkSpeed = 1000.f;
	cmove->JumpZVelocity = 570.f;
	cmove->AirControl = 2.f;
	
}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &APlayerChar::OnUseItem);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerChar::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlayerChar::MoveRight);

	PlayerInputComponent->BindAxis("MouseUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("MouseRight", this, &APawn::AddControllerYawInput);
}

void APlayerChar::MoveForward(float vel) {
	if (vel != 0)
		AddMovementInput(GetActorForwardVector(), vel * moveSpeed);
		//UE_LOG(LogTemp, Warning, TEXT("Forward:"));
}

void APlayerChar::MoveRight(float vel) {
	if (vel != 0)
		AddMovementInput(GetActorRightVector(), vel * moveSpeed);
		//UE_LOG(LogTemp, Warning, TEXT("Right:"));
}

void APlayerChar::OnUseItem() {
	evOnUseItem.Broadcast();
}

