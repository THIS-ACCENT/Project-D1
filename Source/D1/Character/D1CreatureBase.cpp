// Copyright (c) 2025 THIS-ACCENT. All Rights Reserved.


#include "D1CreatureBase.h"
#include "AbilitySystemComponent.h"
#include "D1.h"
#include "Player/D1PlayerState.h"

AD1CreatureBase::AD1CreatureBase()
{
	ASC = nullptr;
}

UAbilitySystemComponent* AD1CreatureBase::GetAbilitySystemComponent() const
{
	return ASC;
}

void AD1CreatureBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AD1PlayerState* GASPS = GetPlayerState<AD1PlayerState>();
	if (GASPS)
	{
		//Setting Ability System Component
		ASC = GASPS->GetAbilitySystemComponent();
		ASC->InitAbilityActorInfo(GASPS, this);

		D1_LOG(LogD1, Log, TEXT("Call ASC Complete!"));

		//Print GAS Debug in Editor viewport
		APlayerController* PlayerController = CastChecked<APlayerController>(NewController);
		PlayerController->ConsoleCommand("showdebug abilitysystem");
	}
}
