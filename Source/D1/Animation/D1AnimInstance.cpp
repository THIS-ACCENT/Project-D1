// Copyright (c) 2025 THIS-ACCENT. All Rights Reserved.


#include "Animation/D1AnimInstance.h"
#include "D1PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UD1AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<ACharacter>(TryGetPawnOwner());
	if (Character)
		MovementComponent = Character->GetCharacterMovement();
}


void UD1AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MovementComponent == nullptr)
		return;

	Speed = Character->GetVelocity().Length();
	IsInAir = MovementComponent->IsFalling();

	{
		const FRotator AimRotator = Character->GetBaseAimRotation();
		const FRotator ActorRotator = Character->GetActorRotation();
		const FRotator DiffRotator = UKismetMathLibrary::NormalizedDeltaRotator(AimRotator, ActorRotator);

		Pitch = DiffRotator.Pitch;
		Roll = DiffRotator.Roll;
		Yaw = DiffRotator.Yaw;
	}

	{
		const FRotator CurrentRotation = Character->GetActorRotation();
		const FRotator DiffRotation = UKismetMathLibrary::NormalizedDeltaRotator(RotationLastTick, CurrentRotation);
		float Target = DiffRotation.Yaw / DeltaSeconds / 7.f;
		YawDelta = UKismetMathLibrary::FInterpTo(YawDelta, Target, DeltaSeconds, 6.f);
		RotationLastTick = CurrentRotation;
	}

	IsAccelerating = MovementComponent->GetCurrentAcceleration().Length() > 0;

	FullBody = GetCurveValue("FullBody") > 0;
}
