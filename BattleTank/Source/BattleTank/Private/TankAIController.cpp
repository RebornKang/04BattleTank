// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	/*
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller not possesing a tank!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller possesing : %s"), *(ControlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("AIController is here"));
	*/
	/*
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (!PlayerTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller find player tank: %s"), *(PlayerTank->GetName()));
	}
	*/
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();
	}
}


