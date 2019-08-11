// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Person.h"
#include "TestPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HOTLINEONLINERM_API ATestPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	// Allows us access to our APerson object properties
	class APerson* MyPawn;

	// Called every frame
	virtual void PlayerTick(float DeltaSeconds) override;
	
	// Here we setup our inputs (movement inputs, mouse inputs, etc.)
	virtual void SetupInputComponent() override;
	
	// Moves our player in the x-direction
	void MoveX(float AxisValue);
	
	// Moves our player in the y-direction
	void MoveY(float AxisValue);

	FVector CurrentVelocity;
};
