// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FlopperamCheck.h"
#include "FlopperamCheckStyle.h"
#include "FlopperamCheckCommands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Kismet/KismetSystemLibrary.h"

#include "LevelEditor.h"

static const FName FlopperamCheckTabName("FlopperamCheck");

#define LOCTEXT_NAMESPACE "FFlopperamCheckModule"

void FFlopperamCheckModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FFlopperamCheckStyle::Initialize();
	FFlopperamCheckStyle::ReloadTextures();

	FFlopperamCheckCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FFlopperamCheckCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FFlopperamCheckModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FFlopperamCheckModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Game", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FFlopperamCheckModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FFlopperamCheckModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FFlopperamCheckStyle::Shutdown();

	FFlopperamCheckCommands::Unregister();
}

void FFlopperamCheckModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText(LOCTEXT("Launching Flopperams Channel...",
		"Would you like to Launch Flopperams Channel?"
	));


	UKismetSystemLibrary::LaunchURL("https://www.youtube.com/channel/UCO77KLKwplncMHLo6gLpIHw");
}

void FFlopperamCheckModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FFlopperamCheckCommands::Get().PluginAction);
}

void FFlopperamCheckModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FFlopperamCheckCommands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFlopperamCheckModule, FlopperamCheck)