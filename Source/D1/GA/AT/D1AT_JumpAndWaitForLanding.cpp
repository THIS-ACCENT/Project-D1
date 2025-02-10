// Copyright (c) 2025 THIS-ACCENT. All Rights Reserved.


#include "GA/AT/D1AT_JumpAndWaitForLanding.h"
#include "GameFramework/Character.h"

UD1AT_JumpAndWaitForLanding::UD1AT_JumpAndWaitForLanding()
{
}

UD1AT_JumpAndWaitForLanding* UD1AT_JumpAndWaitForLanding::CreateTask(UGameplayAbility* OwningAbility)
{
	UD1AT_JumpAndWaitForLanding* NewTask = NewAbilityTask<UD1AT_JumpAndWaitForLanding>(OwningAbility);

	return NewTask;
}

void UD1AT_JumpAndWaitForLanding::Activate()
{
	Super::Activate();

	ACharacter* Character = CastChecked<ACharacter>(GetAvatarActor());
	Character->LandedDelegate.AddDynamic(this, &UD1AT_JumpAndWaitForLanding::OnLandedCallback);
	Character->Jump();

	//언제 끝날지 모르니
	SetWaitingOnAvatar();
}

void UD1AT_JumpAndWaitForLanding::OnDestroy(bool AbilityEnded)
{
	ACharacter* Character = CastChecked<ACharacter>(GetAvatarActor());
	Character->LandedDelegate.RemoveDynamic(this, &UD1AT_JumpAndWaitForLanding::OnLandedCallback);

	Super::OnDestroy(AbilityEnded);
}

void UD1AT_JumpAndWaitForLanding::OnLandedCallback(const FHitResult& Hit)
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnComplete.Broadcast();
	}
}
