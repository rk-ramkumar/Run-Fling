// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Engine/Engine.h"
#include "OnlineSubsystem.h"

UMyGameInstance::UMyGameInstance()
{
	OnlineSubsystem = IOnlineSubsystem::Get();
}

void UMyGameInstance::Init()
{
	Super::PostInitProperties();

	if (OnlineSubsystem)
	{
		SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			MatchmakingCompleteDelegate = FOnMatchmakingCompleteDelegate::CreateUObject(this, &UMyGameInstance::OnMatchmakingComplete);
			MatchmakingCompleteDelegateHandle = SessionInterface->AddOnMatchmakingCompleteDelegate_Handle(MatchmakingCompleteDelegate);

			DestroySessionCompleteDelegate = FOnDestroySessionCompleteDelegate::CreateUObject(this, &UMyGameInstance::OnDestroySessionComplete);
			DestroySessionCompleteDelegateHandle = SessionInterface->AddOnDestroySessionCompleteDelegate_Handle(DestroySessionCompleteDelegate);
		}
	}
}

void UMyGameInstance::StartMatchmaking()
{
	if (SessionInterface.IsValid())
	{
		TArray<FUniqueNetIdRef> PlayerIds;

		FName SessionName = FName(TEXT("MySession"));
		FOnlineSessionSettings Settings;
		TSharedRef<FOnlineSessionSearch> SearchParams = MakeShareable(new FOnlineSessionSearch());

		SessionInterface->StartMatchmaking(PlayerIds, SessionName, Settings, SearchParams);
	}
	
}

void UMyGameInstance::CancelMatchmaking()
{
}

void UMyGameInstance::OnMatchmakingComplete(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Log, TEXT("Matchmaking successful! Joining session."));
		FString ConnectString;
		if (SessionInterface->GetResolvedConnectString(SessionName, ConnectString))
		{
			TransitionToGame(ConnectString);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Matchmaking failed"));
	}
}

void UMyGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Log, TEXT("Session destroyed successfully"));
	}
}

void UMyGameInstance::TransitionToGame(const FString& JoinURL)
{
	if (APlayerController* PC = GetFirstLocalPlayerController())
	{
		PC->ClientTravel(JoinURL, ETravelType::TRAVEL_Absolute);
	}
}
