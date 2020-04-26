// Fill out your copyright notice in the Description page of Project Settings.
#include "RN4UE4.h"
#include "RakNetNetworking.h"
#include "RakNet/Public/Bitstream.h"
#include <string>
NetworkManager* NetworkManager::instance = 0;

#define MAX_CLIENTS 10
#define SERVER_PORT 60000

NetworkManager::NetworkManager()
{
    isServer = false;
    mPeer = RakNet::RakPeerInterface::GetInstance();

	mMessManager = new MessageManager();
}

NetworkManager::~NetworkManager()
{
    RakNet::RakPeerInterface::DestroyInstance(instance->mPeer);
	delete mMessManager;
}

bool NetworkManager::isNetworkStarted()
{
	if (instance == 0)
	{
		return false;
	}
	return true;
}

void NetworkManager::startAsServer()
{
    if (instance == 0)
    {
        instance = new NetworkManager();
        RakNet::SocketDescriptor sd(SERVER_PORT, 0);
        instance->mPeer->Startup(MAX_CLIENTS, &sd, 1);

        instance->isServer = true;

        instance->mPeer->SetMaximumIncomingConnections(MAX_CLIENTS);
    }

}

void NetworkManager::startAsClient(FString address)
{
    if (instance == 0)
    {
        instance = new NetworkManager();
        RakNet::SocketDescriptor sd;
        instance->mPeer->Startup(1,&sd,1);

        instance->isServer = false;
        
        std::string stringAddress(TCHAR_TO_UTF8(*address));
        char* str = new char[stringAddress.length() + 1];
        std::strcpy(str, stringAddress.c_str());

        //connect to server
        instance->mPeer->Connect(str, SERVER_PORT, 0, 0);
    }
 
}

void NetworkManager::destroyNetwork()
{   
    //unload any nessassary data, memory
    delete instance;
}

void NetworkManager::clientSendMessage(int32 toAddress,GameID type, FString message)
{
	RakNet::BitStream bsOut[1];
	bsOut->Write((RakNet::MessageID)UNREAL_MESSAGE);

	std::string stringMessage(TCHAR_TO_UTF8(*message));
	
	bsOut->Write(toAddress);
	bsOut->Write((int32)type);
	bsOut->Write(stringMessage);

	//because the client only has one connection which is server, if it is broadcast it will only send to server
	instance->mPeer->Send(bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_SYSTEM_ADDRESS , true);
}

void NetworkManager::ServerSendMessage(int32 toAddress, GameID type, FString Message, bool broadCast)
{
	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)UNREAL_MESSAGE);

	std::string stringMessage(TCHAR_TO_UTF8(*Message));

	bsOut.Write(toAddress);
	bsOut.Write((int32)type);
	bsOut.Write(stringMessage);
	
	if (broadCast)
	{
		instance->mPeer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_SYSTEM_ADDRESS, true);
	}
	else
	{
		instance->mPeer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, instance->addressList[toAddress], false);
	}
}

void NetworkManager::receiveMessage()
{
	RakNet::Packet* packet;

	for (packet = instance->mPeer->Receive(); packet; instance->mPeer->DeallocatePacket(packet), packet = instance->mPeer->Receive())
	{
		switch (packet->data[0])
		{
		case ID_REMOTE_DISCONNECTION_NOTIFICATION:
			printf("Another client has disconnected.\n");
			break;
		case ID_REMOTE_CONNECTION_LOST:
			printf("Another client has lost the connection.\n");
			break;
		case ID_REMOTE_NEW_INCOMING_CONNECTION:
			printf("Another client has connected.\n");
			break;
		case ID_CONNECTION_REQUEST_ACCEPTED:
		{
			printf("Our connection request has been accepted.\n");

			// Use a BitStream to write a custom user message
			// Bitstreams are easier to use than sending casted structures, and handle endian swapping automatically
			if (instance->isServer)
			{
				instance->addressList.Add(packet->systemAddress);
				int32 index = instance->addressList.Num();
				index--;
				RakNet::BitStream bsOut;

				bsOut.Write((RakNet::MessageID)CLIENT_CONNECTED);
				bsOut.Write("index");
				instance->mPeer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, packet->systemAddress, true);
			}
		}
		break;
		case ID_NEW_INCOMING_CONNECTION:
			printf("A connection is incoming.\n");
			break;
		case ID_NO_FREE_INCOMING_CONNECTIONS:
			printf("The server is full.\n");
			break;
		case ID_DISCONNECTION_NOTIFICATION:
			if (instance->isServer) {
				printf("A client has disconnected.\n");
			}
			else {
				printf("We have been disconnected.\n");
			}
			break;
		case ID_CONNECTION_LOST:
			if (instance->isServer) {
				printf("A client lost the connection.\n");
			}
			else {
				printf("Connection lost.\n");
			}
			break;

		case UNREAL_MESSAGE:
		{
			RakNet::RakString rs;
			RakNet::BitStream bsIn(packet->data, packet->length, false);
			bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
			
			int32 toAddress;
			int32 gameID; 
			
			bsIn.Read(toAddress);
			bsIn.Read(gameID);
			bsIn.Read(rs);
			
			NetMessage netMessage;
			netMessage.gameID = (GameID)gameID;
			netMessage.message = FString(rs.C_String());

			//send direct message
			if (instance->isServer && toAddress != -1 && toAddress < instance->addressList.Num())
			{
				instance->ServerSendMessage(toAddress, netMessage.gameID, netMessage.message, false);
			}
			//resend client message to all
			else if(instance->isServer && toAddress == -1)
			{
				RakNet::BitStream bsOut;
				bsOut.Write((RakNet::MessageID)UNREAL_MESSAGE);

				bsOut.Write(toAddress);
				bsOut.Write((int32)netMessage.gameID);
				bsOut.Write(netMessage.message);

				instance->mPeer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, packet->systemAddress, true);
			}

			instance->mMessManager->addNewMessage(netMessage);
		}
		break;
		case CLIENT_CONNECTED:
		{
			RakNet::RakString rs;
			RakNet::BitStream bsIn(packet->data, packet->length, false);
			bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

			int addressID;
			bsIn.Read(addressID);

			instance->intAddressList.Add(addressID);
		}
		break;

		default:
			printf("Message with identifier %i has arrived.\n", packet->data[0]);
			break;
		}
	}
}

MessageManager* NetworkManager::getMessageManager()
{
	return instance->mMessManager;
}