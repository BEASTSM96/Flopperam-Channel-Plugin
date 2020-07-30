// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "FlopperamCheckStyle.h"

class FFlopperamCheckCommands : public TCommands<FFlopperamCheckCommands>
{
public:

	FFlopperamCheckCommands()
		: TCommands<FFlopperamCheckCommands>(TEXT("FlopperamCheck"), NSLOCTEXT("Contexts", "FlopperamCheck", "FlopperamCheck Plugin"), NAME_None, FFlopperamCheckStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
