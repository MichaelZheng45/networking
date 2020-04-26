// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UnrealString.h"
#include "RakNet/Public/RakPeerInterface.h"
#include "RakNet/Public/GetTime.h"
#include "RakNet/Public/MessageIdentifiers.h"
#include "RakNetNetworking/MessageManager.h"


enum GameMessages
{
	UNREAL_MESSAGE = ID_USER_PACKET_ENUM + 1,
	CLIENT_CONNECTED
};

class RN4UE4_API NetworkManager
{

public:

	static bool isNetworkStarted();

	static void startAsServer();

	static void startAsClient(FString address);

	static void destroyNetwork();

	static void clientSendMessage(int32 toAddress, GameID type, FString message);

	static void ServerSendMessage(int32 toAddress, GameID type, FString Message, bool broadCast);
	
	static void receiveMessage();

	static MessageManager* getMessageManager();
	private:
		static NetworkManager* instance;

		NetworkManager();
		~NetworkManager();
		//networkData
		bool isServer = false;

		RakNet::RakPeerInterface* mPeer;

		MessageManager* mMessManager;

		//for client 
		TArray<int32> intAddressList;
		
		//for server
		TArray<RakNet::SystemAddress> addressList;
};