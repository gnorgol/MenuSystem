// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void MenuSetup(int32 NumberOfPublicConnections = 4 , FString TypeOfMatch = TEXT("FreeForAll"));

protected:
	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	// Callbacks for the custom delegates
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
private:

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UFUNCTION()
	void HostButtonClicked();
	UFUNCTION()
	void JoinButtonClicked();

	void MenuTeardown();

	//The Subsystem that will be used to create the session
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	int32 MaxNumPlayers{ 4 };
	FString GameMode {TEXT("FreeForAll")};
};
