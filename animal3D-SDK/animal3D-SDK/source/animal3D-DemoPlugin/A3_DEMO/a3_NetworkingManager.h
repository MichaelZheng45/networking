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
	
	a3_NetworkingManager.h
	Networking manager interface.
*/

#ifndef __ANIMAL3D_NETWORKINGMANAGER_H
#define __ANIMAL3D_NETWORKINGMANAGER_H

//-----------------------------------------------------------------------------
// animal3D framework includes
#include "animal3D/animal3D.h"
#include "RakNet/GetTime.h"
#include "RakNet/RakPeerInterface.h"
#include "a3_Networking/Events/EventStructures/EventManager.h"
//-----------------------------------------------------------------------------

#ifdef  __cplusplus

	enum netType
	{
		NETYPE_PUSH,
		NETYPE_SHARED,
		NETYPE_COUPLED
	};

	typedef a3byte a3netAddressStr[16];

	// networking manager
	class a3_NetworkingManager
	{
		public:
		static a3_NetworkingManager* getInstance() {return instance;}

		a3_NetworkingManager();
		~a3_NetworkingManager();

		// startup networking
		a3i32 a3netStartup( a3ui16 port_inbound, a3ui16 port_outbound, a3ui16 maxConnect_inbound, a3ui16 maxConnect_outbound);

		// shutdown networking
		a3i32 a3netShutdown();

		// connect
		a3i32 a3netConnect( a3netAddressStr const ip);

		// disconnect
		a3i32 a3netDisconnect();

		// process inbound packets
		a3i32 a3netProcessInbound();

		// process outbound packets
		a3i32 a3netProcessOutbound();

		a3i32 a3netIdentity(a3boolean isServer);

		a3i32 a3netSetType(netType type);

		a3i32 a3netProcessEvents();

		a3i32 a3netSendMoveEvent( a3i32 objID, a3i32 x, a3i32 y);

		a3i32 a3netInitGameEvent(a3i32 id, a3i32 xSize, a3i32 ySize);

		private:
		static a3_NetworkingManager* instance;
	
		a3ui16 port_inbound, port_outbound;
		a3ui16 maxConnect_inbound, maxConnect_outbound;
		RakNet::RakPeerInterface* mPeer;

		a3boolean isServer;
		netType networkType;
		EventManager* eventMan;
	};


//-----------------------------------------------------------------------------
#else
	typedef struct a3_NetworkingManager a3_NetworkingManager
	
#endif //  __cplusplus

#endif	// !__ANIMAL3D_NETWORKINGMANAGER_H