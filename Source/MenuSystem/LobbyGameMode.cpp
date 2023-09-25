// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (GameState)
	{
		int32 NumOfPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Yellow, FString::Printf(TEXT("Players in game: %d"), NumOfPlayers));
			APlayerState* playerState = NewPlayer->GetPlayerState<APlayerState>();

			GEngine->AddOnScreenDebugMessage(2, 60.f, FColor::Cyan, FString::Printf(TEXT("%s has joined"), *playerState->GetPlayerName()));
		}

	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	if (GameState)
	{
		int32 NumOfPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Yellow, FString::Printf(TEXT("Players in game: %d"), NumOfPlayers - 1));
			APlayerState* playerState = Exiting->GetPlayerState<APlayerState>();

			GEngine->AddOnScreenDebugMessage(2, 60.f, FColor::Cyan, FString::Printf(TEXT("%s has left"), *playerState->GetPlayerName()));
		}

	}

}
