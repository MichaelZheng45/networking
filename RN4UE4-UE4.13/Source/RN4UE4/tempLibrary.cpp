// Fill out your copyright notice in the Description page of Project Settings.

#include "RN4UE4.h"
#include "tempLibrary.h"

bool UtempLibrary::networkActive()
{
	return NetworkManager::isNetworkStarted();
}

void UtempLibrary::beginNetworkAsServer()
{
	NetworkManager::startAsServer();
}

void UtempLibrary::beginNetworkAsClient(FString address)
{
	NetworkManager::startAsClient(address);
}

void UtempLibrary::destroyNetwork()
{
	NetworkManager::destroyNetwork();
}

void UtempLibrary::SendMessageAsClient(int32 toAddress, GameID type, FString message)
{
	NetworkManager::clientSendMessage(toAddress, type, message);
}

void UtempLibrary::SendMessageAsServer(int32 toAddress, GameID type, FString Message, bool broadCast)
{
	NetworkManager::ServerSendMessage(toAddress, type, Message, broadCast);
}

void UtempLibrary::receiveIncomingMessage()
{
	NetworkManager::receiveMessage();
}

FString UtempLibrary::readRecentMessage()
{
	return NetworkManager::getMessageManager()->readLatestMessage().message;
}

bool UtempLibrary::readRecentMessageOfGameID(GameID type, FString& messOut)
{
	NetMessage message;
	bool found = NetworkManager::getMessageManager()->readMessageOfGameID(type, message);
	messOut = message.message;
	return found;
}




