// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnrealString.h"
#include "RakNetNetworking/RakNetNetworking.h"
#include "tempLibrary.generated.h"

/**
 * 
 */
UCLASS()
class RN4UE4_API UtempLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "RaKNet Networking")
		static bool networkActive();

	UFUNCTION(BlueprintCallable, Category = "RaKNet Networking")
		static void beginNetworkAsServer();

	UFUNCTION(BlueprintCallable, Category = "RaKNet Networking")
		static void beginNetworkAsClient(FString address);

	UFUNCTION(BlueprintCallable, Category = "RaKNet Networking")
		static void destroyNetwork();

	UFUNCTION(BlueprintCallable, Category = "RaKNet Networking")
		static void SendMessageAsClient(int32 toAddress, GameID type, FString message);

	//if broad cast is true, send to all otherwise send to address id
	UFUNCTION(BlueprintCallable, Category = "RaKNet Networking")
		static void SendMessageAsServer(int32 toAddress, GameID type, FString Message, bool broadCast);

	UFUNCTION(BlueprintCallable, Category = "RaKNet Networking")
		static void receiveIncomingMessage();

	UFUNCTION(BlueprintCallable, Category = "Message Manager")
		static FString readRecentMessage();

	UFUNCTION(BlueprintCallable, Category = "Message Manager")
		static bool readRecentMessageOfGameID(GameID type, FString& messOut);

};
