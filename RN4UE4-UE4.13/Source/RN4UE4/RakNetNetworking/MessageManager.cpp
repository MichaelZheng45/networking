#include "RN4UE4.h"
#include "MessageManager.h"

MessageManager::MessageManager()
{
}

MessageManager::~MessageManager()
{
}

NetMessage MessageManager::readLatestMessage()
{
	NetMessage mes = messages[0];
	messages.RemoveAt(0);

	return mes;
}

bool MessageManager::readMessageOfGameID(GameID type, NetMessage& messOut)
{
	for (int32 i = 0; i < messages.Num(); i++)
	{
		if (messages[i].gameID == type)
		{
			messOut = messages[i];
			messages.RemoveAt(i);
			return true;
		}
	}

	return false;
}


void MessageManager::addNewMessage(NetMessage newMessage)
{
	messages.Add(newMessage);
}
