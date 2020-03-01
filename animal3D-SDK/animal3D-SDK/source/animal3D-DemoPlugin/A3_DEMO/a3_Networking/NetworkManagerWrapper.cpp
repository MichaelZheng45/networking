#include "NetworkManagerWrapper.h"
#include "A3_DEMO/a3_NetworkingManager.h"
extern "C"
{
	// startup networking
	a3i32 a3netWStartup(a3_NetworkingManager* net, a3ui16 port_inbound, a3ui16 port_outbound, a3ui16 maxConnect_inbound, a3ui16 maxConnect_outbound)
	{
		net->a3netStartup(port_inbound, port_outbound, maxConnect_inbound, maxConnect_outbound);
	}

	// shutdown networking
	a3i32 a3netWShutdown(a3_NetworkingManager* net)
	{
		net->a3netShutdown();
	}

	// connect
	a3i32 a3netWConnect(a3_NetworkingManager* net, a3netAddressStr const ip)
	{
		net->a3netConnect(ip);
	}

	// disconnect
	a3i32 a3netWDisconnect(a3_NetworkingManager* net)
	{
		net->a3netDisconnect();
	}


	// process inbound packets
	a3i32 a3netWProcessInbound(a3_NetworkingManager* net)
	{
		net->a3netProcessInbound();
	}

	// process outbound packets
	a3i32 a3netWProcessOutbound(a3_NetworkingManager* net)
	{
		net->a3netProcessOutbound();
	}

	a3i32 a3netWIdentity(a3_NetworkingManager* net, a3boolean isServer)
	{
		net->a3netIdentity(isServer);
	}

	a3i32 a3netWProcessEvents(a3_NetworkingManager* net)
	{
		net->a3netProcessEvents();
	}

	a3i32 a3netWSendMoveEvent(a3_NetworkingManager* net, a3i32 objID, a3i32 x, a3i32 y)
	{
	
	}

	a3i32 a3netWSetType(a3_NetworkingManager* net, int type)
	{
		net->a3netSetType(static_cast<netType>(type));
	}
}