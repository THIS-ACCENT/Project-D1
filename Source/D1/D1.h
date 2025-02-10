// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//make Log print call function info
#define LOG_CALLINFO ANSI_TO_TCHAR(__FUNCTION__)
#define D1_LOG(LogCat, Verbosity, Format, ...) UE_LOG(LogCat, Verbosity, TEXT("%s %s"), LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

/*
 * Add log category.
 * - if you add some CATEGORY in here, define log category in cpp file.
 */

DECLARE_LOG_CATEGORY_EXTERN(LogD1, Log, All);

