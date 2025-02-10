// Copyright (c) 2025 THIS-ACCENT. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "D1CreatureBase.generated.h"

UCLASS()
class D1_API AD1CreatureBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AD1CreatureBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy(AController* NewController) override;

private:
	UPROPERTY(EditAnywhere, Category = "GAS")
	TObjectPtr<class UAbilitySystemComponent> ASC;
};
