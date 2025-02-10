// Copyright (c) 2025 THIS-ACCENT. All Rights Reserved.


#include "Player/D1PlayerController.h"

void AD1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}
