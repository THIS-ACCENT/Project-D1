// Copyright (c) 2025 THIS-ACCENT. All Rights Reserved.


#include "Player/D1PlayerState.h"
#include "AbilitySystemComponent.h"

AD1PlayerState::AD1PlayerState()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
	//TODO: Make AttributeSet CDO
}

class UAbilitySystemComponent* AD1PlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}
