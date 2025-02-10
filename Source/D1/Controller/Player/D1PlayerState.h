// Copyright (c) 2025 THIS-ACCENT. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "D1PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class D1_API AD1PlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AD1PlayerState();
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	UPROPERTY(EditAnywhere, Category = "GAS")
	TObjectPtr<class UAbilitySystemComponent> ASC;

	//TODO: Add Attribute Set Class
};
