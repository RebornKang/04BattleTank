// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enums
UENUM()
enum EFiringStatus 
{
	Reloading,
	Aiming,
    Locked
};

class UTankBarrel;
class UTankTurret;


// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	TEnumAsByte<EFiringStatus> FiringState = EFiringStatus::Reloading;

private:	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret= nullptr;

	
	void MoveBarrelTowards(FVector AimDirection);

public:	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	// void SetBarrelReference(UTankBarrel* BarrelToSet);
	// void SetTurretReference(UTankTurret* TurretToSet);

	// Sets default values for this component's properties
	UTankAimingComponent();

	// ToDo add SetTurretRefference

	void AimAt(FVector HitLocation, float LaunchSpeed);


	/*
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts
	virtual void BeginPlay() override;
	*/

	
};
