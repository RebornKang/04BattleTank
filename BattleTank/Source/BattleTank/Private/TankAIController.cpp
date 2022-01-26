// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

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
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller find player tank: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
