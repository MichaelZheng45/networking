#include "NetworkManagerWrapper.h"
#include "A3_DEMO/a3_NetworkingManager.h"
extern "C"
{
	a3_NetworkingManager* newNetworkManager()
	{
		a3_NetworkingManager* instance = a3_NetworkingManager::getInstance();
		instance = new a3_NetworkingManager();
		return instance;
	}

	// startup networking
	a3i32 a3netWStartup(a3_NetworkingManager* net, a3ui16 port_inbound, a3ui16 port_outbound, a3ui16 maxConnect_inbound, a3ui16 maxConnect_outbound)
	{
		net->a3netStartup(port_inbound, port_outbound, maxConnect_inbound, maxConnect_outbound);
		return 0;
	}

	// shutdown networking
	a3i32 a3netWShutdown(a3_NetworkingManager* net)
	{
		net->a3netShutdown();
		return 0;
	}

	// connect
	a3i32 a3netWConnect(a3_NetworkingManager* net, a3netAddressStr const ip)
	{
		net->a3netConnect(ip);
		return 0;
	}

	// disconnect
	a3i32 a3netWDisconnect(a3_NetworkingManager* net)
	{
		net->a3netDisconnect();
		return 0;
	}


	// process inbound packets
	a3i32 a3netWProcessInbound(a3_NetworkingManager* net)
	{
		net->a3netProcessInbound();
		return 0;
	}

	// process outbound packets
	a3i32 a3netWProcessOutbound(a3_NetworkingManager* net)
	{
		net->a3netProcessOutbound();
		return 0;
	}

	a3i32 a3netWIdentity(a3_NetworkingManager* net, a3boolean isServer)
	{
		net->a3netIdentity(isServer);
		return 0;
	}

	a3i32 a3netWProcessEvents(a3_NetworkingManager* net)
	{
		net->a3netProcessEvents();
		return 0;
	}

	a3i32 a3netWSendMoveEvent(a3_NetworkingManager* net, a3i32 objID, a3i32 x, a3i32 y)
	{
		net->a3netSendMoveEvent(objID, x, y);
		return 0;
	}

	a3i32 a3netWSetType(a3_NetworkingManager* net, a3i32 type)
	{
		net->a3netSetType(static_cast<netType>(type));
		return 0;
	}

	a3i32 a3netSendInitGame(a3_NetworkingManager* net, a3i32 id, a3i32 xSize, a3i32 ySize)
	{
		net->a3netInitGameEvent(id, xSize, ySize);
		return 0;
	}
}