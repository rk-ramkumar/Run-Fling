// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class RUNANDFLING_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();

	virtual void Init() override;
	
	UFUNCTION(BlueprintCallable)
	void StartMatchmaking();

	UFUNCTION(BlueprintCallable)
	void CancelMatchmaking();

private:
	IOnlineSubsystem* OnlineSubsystem;
	IOnlineSessionPtr SessionInterface;

	//Matchmaking Delegates
	FOnMatchmakingCompleteDelegate MatchmakingCompleteDelegate;
	FDelegateHandle MatchmakingCompleteDelegateHandle;

	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FDelegateHandle DestroySessionCompleteDelegateHandle;

	//Matchmaking Callbacks
	void OnMatchmakingComplete(FName SessionName, bool bWasSuccessful);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

	//Utility Functions
	void TransitionToGame(const FString& JoinURL);
};
