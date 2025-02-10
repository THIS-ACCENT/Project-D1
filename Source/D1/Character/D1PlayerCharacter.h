// Copyright (c) 2025 THIS-ACCENT. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/D1CreatureBase.h"
#include "InputActionValue.h"
#include "D1PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class D1_API AD1PlayerCharacter : public AD1CreatureBase
{
	GENERATED_BODY()
public:
	AD1PlayerCharacter();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void SetupGASInputComponent();
	void GASInputPressed(int32 InputId);
	void GASInputReleased(int32 InputId);

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

// Camera Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;
// Input Section
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> LookAction;

//GAS Section
protected:
	UPROPERTY(EditAnyWhere, Category = "GAS")
	TArray<TSubclassOf<class UGameplayAbility>> StartAbilities;

	UPROPERTY(EditAnyWhere, Category = "GAS")
	TMap<int32, TSubclassOf<class UGameplayAbility>> StartInputAbilities;

};