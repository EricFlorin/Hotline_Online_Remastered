// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerController.h"

void ATestPlayerController::PlayerTick(float DeltaSeconds)
{
	Super::PlayerTick(DeltaSeconds);
	// Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (APerson* MyPawn = Cast<APerson>(GetPawn()))
		{
			if (!CurrentVelocity.IsZero())
			{
				FVector NewLocation = MyPawn->GetActorLocation() + (CurrentVelocity * DeltaSeconds);
				MyPawn->SetActorLocation(NewLocation);
			}
		}
	}
}

void ATestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Figure out how to clamp movement

	InputComponent->BindAxis(TEXT("MoveX"), this, &ATestPlayerController::MoveX);
	InputComponent->BindAxis(TEXT("MoveY"), this, &ATestPlayerController::MoveY);
}

void ATestPlayerController::MoveX(float AxisValue)
{
	APawn* pawn = this->GetPawn();
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	UE_LOG(LogTemp, Log, TEXT("MoveX: %f"), AxisValue);
}

void ATestPlayerController::MoveY(float AxisValue)
{
	APawn* pawn = this->GetPawn();
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	UE_LOG(LogTemp, Log, TEXT("MoveY: %f"), AxisValue);
}