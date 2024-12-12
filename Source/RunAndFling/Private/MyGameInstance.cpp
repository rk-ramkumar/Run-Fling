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

void UMyGameInstance::StartMatching()
{
}

void UMyGameInstance::CancelMatching()
{
}

void UMyGameInstance::OnMatchmakingComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMyGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMyGameInstance::TransitionToGame(const FString& JoinURL)
{
}
