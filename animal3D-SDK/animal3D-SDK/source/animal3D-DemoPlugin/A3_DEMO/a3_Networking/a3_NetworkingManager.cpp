/*
	Copyright 2011-2020 Daniel S. Buckstein

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

/*
	animal3D SDK: Minimal 3D Animation Framework
	By Daniel S. Buckstein
	
	a3_NetworkingManager.cpp
	RakNet networking wrapper.
*/


#include "../a3_NetworkingManager.h"
#include "A3_DEMO/a3_Networking/Events/EventNodes/NetEvent.h"
#include "A3_DEMO/a3_Networking/Events/EventNodes/MoveEvent.h"
#include "A3_DEMO/a3_Networking/Events/EventNodes/InitGameEvent.h"
#include "RakNet/BitStream.h"
#include <string>
//-----------------------------------------------------------------------------
// networking stuff
a3_NetworkingManager* a3_NetworkingManager::instance = 0;

a3_NetworkingManager::a3_NetworkingManager()
{
	eventMan = nullptr;
	mPeer = nullptr;
}

a3_NetworkingManager::~a3_NetworkingManager()
{
}

// startup networking
a3i32 a3_NetworkingManager::a3netStartup( a3ui16 nPort_inbound, a3ui16 nPort_outbound, a3ui16 nMaxConnect_inbound, a3ui16 nMaxConnect_outbound)
{
	if (mPeer == nullptr)
	{
		RakNet::RakPeerInterface* peer = RakNet::RakPeerInterface::GetInstance();
		if (peer != nullptr)
		{
			port_inbound = nPort_inbound;
			port_outbound = nPort_outbound;
			maxConnect_inbound = nMaxConnect_inbound;
			maxConnect_outbound = nMaxConnect_outbound;

			RakNet::SocketDescriptor socket[2] = {
				RakNet::SocketDescriptor(port_inbound, 0),		// server settings
				RakNet::SocketDescriptor(),	// client settings
			};

			// choose startup settings based on 
			a3boolean const isServer = port_inbound && maxConnect_inbound;
			a3boolean const isClient = port_outbound && maxConnect_outbound;
			if (peer->Startup(maxConnect_inbound + maxConnect_outbound, socket + isClient, 1) == RakNet::StartupResult::RAKNET_STARTED)
			{
				peer->SetMaximumIncomingConnections(maxConnect_inbound);
				peer->SetOccasionalPing(true);

				mPeer = peer;

				eventMan = new EventManager();
				return 1;
			}
		}
	}
	return 0;
}

// shutdown networking
a3i32 a3_NetworkingManager::a3netShutdown()
{
	if (mPeer != nullptr)
	{
		delete eventMan;
		RakNet::RakPeerInterface* peer = mPeer;
		RakNet::RakPeerInterface::DestroyInstance(peer);
		peer = 0;
		delete this;
		return 1;
	}
	return 0;
}


// connect
a3i32 a3_NetworkingManager::a3netConnect( a3netAddressStr const ip)
{
	if (mPeer != nullptr)
	{
		RakNet::RakPeerInterface* peer = mPeer;
		peer->Connect(ip,port_outbound, 0, 0);
		return 1;
	}
	return 0;
}

// disconnect
a3i32 a3_NetworkingManager::a3netDisconnect()
{
	if (mPeer != nullptr)
	{
		RakNet::RakPeerInterface* peer = mPeer;
		a3ui16 i, j = peer->NumberOfConnections();
		for (i = 0; i < j; ++i)
			peer->CloseConnection(peer->GetSystemAddressFromIndex(i), true);
		return 1;
	}
	return 0;
}


// process inbound packets
a3i32 a3_NetworkingManager::a3netProcessInbound()
{
	if (mPeer)
	{
		RakNet::RakPeerInterface* peer = mPeer;
		RakNet::Packet* packet;
		RakNet::MessageID msg;
		a3i32 count = 0;
		for (packet = peer->Receive();
			packet;
			peer->DeallocatePacket(packet), packet = peer->Receive(), ++count)
		{
			RakNet::BitStream bs_in(packet->data, packet->length, false);
			bs_in.Read(msg);

			switch (packet->data[0])
			{
				// check for timestamp and process
			case ID_TIMESTAMP:

				//dt = peer->GetClockDifferential(packet->systemAddress);
				//printf("Clock diff: %u \n", (unsigned int)dt);
				// do not break; proceed to default case to process actual message contents
			default:
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
					printf("Our connection request has been accepted.\n");
					{
						printf("yes");
						/*
						RakNet::BitStream bsOut[1];

						//indicate time stamped
						bsOut->Write((RakNet::MessageID)ID_TIMESTAMP);
						//get time
						RakNet::Time sendTime = RakNet::GetTime();
						bsOut->Write(sendTime);

						bsOut->Write((RakNet::MessageID)ID_GAME_MESSAGE_1);
						bsOut->Write("Networking is fun");
						peer->Send(bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, packet->systemAddress, false);

						*/
						
						//recieved connection/ proceed to send message to server it is notified
						if (!isServer)
						{
							RakNet::BitStream bsOut[1];
							bsOut->Write((RakNet::MessageID)ID_CLIENT_NOTIFIED);
							peer->Send(bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, packet->systemAddress, false);
						}
					}
					break;
				case ID_GAME_INIT_EVENT:
					{
						printf("Recieved Event, adding to eventmanager");
						//MoveEvent nEvent = *(MoveEvent*)mes;
						RakNet::RakString rs;
						RakNet::BitStream bsIn(packet->data, packet->length, false);
						bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
						//bsIn.Read(rs);
						//InitGameEvent nEvent = *(InitGameEvent*)(rs.C_String());
						//eventMan->addEvent(&nEvent);
						a3i32 id;
						a3i32 x;
						a3i32 y;
						a3i32 time;

						bsIn.Read(id);
						bsIn.Read(x);
						bsIn.Read(y);
						bsIn.Read(time);
						InitGameEvent* nEvent = new InitGameEvent(id, time, x,y);
						eventMan->addEvent(nEvent);
					}
					break;
				case ID_GAME_MOVE_EVENT:
					{
						printf("Recieved Event, adding to eventmanager");
						//MoveEvent nEvent = *(MoveEvent*)mes;
						RakNet::RakString rs;
						RakNet::BitStream bsIn(packet->data, packet->length, false);
						bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
						//bsIn.Read(rs);
						//MoveEvent nEvent = *(MoveEvent*)(rs.C_String());
						
						a3i32 id;
						a3i32 x;
						a3i32 y;
						a3i32 time;

						bsIn.Read(id);
						bsIn.Read(x);
						bsIn.Read(y);
						bsIn.Read(time);
						MoveEvent* nEvent = new MoveEvent(id,x,y,time);
						eventMan->addEvent(nEvent);
					}
					break;
				case ID_CLIENT_NOTIFIED:
					printf("Client is notified.\n");
					{
					}
					break;
				case ID_NEW_INCOMING_CONNECTION:
					printf("A connection is incoming.\n");

					break;
				case ID_NO_FREE_INCOMING_CONNECTIONS:
					printf("The server is full.\n");
					break;
				case ID_DISCONNECTION_NOTIFICATION:
					if (maxConnect_outbound) {
						printf("A client has disconnected.\n");
					}
					else {
						printf("We have been disconnected.\n");
					}
					break;
				case ID_CONNECTION_LOST:
					if (maxConnect_outbound) {
						printf("A client lost the connection.\n");
					}
					else {
						printf("Connection lost.\n");
					}
					break;

				case ID_GAME_MESSAGE_1:
					printf("DEBUG MESSAGE: received packet ID_GAME_MESSAGE_1.\n");
					{
						RakNet::RakString rs;
						bs_in.Read(rs);
						printf("%s\n", rs.C_String());
					}
					break;

				default:
					printf("Message with identifier %i has arrived.\n", msg);
					break;
				}
				break;
			}
		}
		return count;
	}
	return 0;
}

// process outbound packets
a3i32 a3_NetworkingManager::a3netProcessOutbound()
{
	if (mPeer)
	{

	}
	return 0;
}
a3i32 a3_NetworkingManager::a3netIdentity(a3boolean isServer)
{
	isServer = isServer;

	return 0;
}

a3i32 a3_NetworkingManager::a3netProcessEvents()
{
	int count = eventMan->getNodeCount();
	for (int i = 0; i < count; i++)
	{
		eventMan->executeEvent();
	}

	return 0;
}

a3i32 a3_NetworkingManager::a3netSendMoveEvent(a3i32 objID, a3i32 x, a3i32 y)
{
	RakNet::RakPeerInterface* peer = mPeer;
	RakNet::Time sendTime = RakNet::GetTime();

	//send message
//	peer->Send(reinterpret_cast<char*>(&MoveEvent(objID, x, y, (a3i32)sendTime)), sizeof(MoveEvent), HIGH_PRIORITY, RELIABLE_ORDERED, 0, peer->GetSystemAddressFromIndex(0), false);
	
	
	char* mes = reinterpret_cast<char*>(&MoveEvent(objID, x, y, (a3i32)sendTime));
	RakNet::BitStream bsOut[1];

	bsOut->Write((RakNet::MessageID)ID_GAME_MOVE_EVENT);

	//RakNet::RakString rs;
	//rs.Set(mes, sizeof(MoveEvent));
	//bsOut->Write(rs);
	bsOut->Write(objID);
	bsOut->Write(x);
	bsOut->Write(y);
	bsOut->Write((a3i32)sendTime);

	//bsOut->Write((char*)&MoveEvent(objID, x, y, (a3i32)sendTime), sizeof(MoveEvent));
	peer->Send(bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_SYSTEM_ADDRESS, true);
	return 0;
}

a3i32 a3_NetworkingManager::a3netInitGameEvent(a3i32 id, a3i32 xSize, a3i32 ySize)
{
	RakNet::RakPeerInterface* peer = mPeer;
	RakNet::Time sendTime = RakNet::GetTime();

	//send message
	//peer->Send(reinterpret_cast<char*>(&*moveEvent), sizeof(moveEvent), HIGH_PRIORITY, RELIABLE_ORDERED, 0, peer->GetSystemAddressFromIndex(0), false);
	char* mes = reinterpret_cast<char*>(&InitGameEvent(id, xSize, ySize, (a3i32)sendTime));

	RakNet::BitStream bsOut[1];

	bsOut->Write((RakNet::MessageID)ID_GAME_INIT_EVENT);
	
	//RakNet::RakString rs;
	//rs.Set(mes);
	//bsOut->Write(rs);
	bsOut->Write(id);
	bsOut->Write(xSize);
	bsOut->Write(ySize);
	bsOut->Write((a3i32)sendTime);
	peer->Send(bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_SYSTEM_ADDRESS, true);
	return 0;
}

a3i32 a3_NetworkingManager::a3netSetType(netType type)
{
	networkType = type;
	return 0;
}
//-----------------------------------------------------------------------------
