#pragma once


#include "NetMessages.h"

class RN4UE4_API MessageManager
{
public:
	MessageManager();
	~MessageManager();

	NetMessage readLatestMessage();
	bool readMessageOfGameID(GameID type, NetMessage& messOut);

	void addNewMessage(NetMessage newMessage);
private:
	TArray<NetMessage> messages;	
};

