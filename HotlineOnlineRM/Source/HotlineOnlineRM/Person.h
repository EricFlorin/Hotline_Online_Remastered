// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/ArrowComponent.h"
#include "Camera/CameraComponent.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Person.generated.h"



UCLASS()
class HOTLINEONLINERM_API APerson : public APawn
{
	GENERATED_BODY()

private:
	// Helpful debug tool - which way is the tank facing?
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Person", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* PersonDirection;

	// Sprite for the tank body.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Person", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* PersonSprite;

	// Our in-game camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Person", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Sets default values for this pawn's properties
	APerson();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
