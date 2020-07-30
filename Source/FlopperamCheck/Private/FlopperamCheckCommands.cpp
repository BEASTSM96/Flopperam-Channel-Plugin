// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FlopperamCheckCommands.h"

#define LOCTEXT_NAMESPACE "FFlopperamCheckModule"

void FFlopperamCheckCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "FlopperamCheck", "Get Flopperams Channel", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
