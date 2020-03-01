#ifndef NETWORKMANAGERWRAPPER_H
#define NETWORKMANAGERWRAPPER_H

#include "animal3D/animal3D.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	typedef a3byte a3netAddressStr[16];
	typedef struct a3_NetworkingManager a3_NetworkingManager;

	// startup networking
	a3i32 a3netWStartup(a3_NetworkingManager* net, a3ui16 port_inbound, a3ui16 port_outbound, a3ui16 maxConnect_inbound, a3ui16 maxConnect_outbound);

	// shutdown networking
	a3i32 a3netWShutdown(a3_NetworkingManager* net);

	// connect
	a3i32 a3netWConnect(a3_NetworkingManager* net, a3netAddressStr const ip);

	// disconnect
	a3i32 a3netWDisconnect(a3_NetworkingManager* net);


	// process inbound packets
	a3i32 a3netWProcessInbound(a3_NetworkingManager* net);

	// process outbound packets
	a3i32 a3netWProcessOutbound(a3_NetworkingManager* net);

	a3i32 a3netWIdentity(a3_NetworkingManager* net, a3boolean isServer);

	a3i32 a3netWProcessEvents(a3_NetworkingManager* net);

	a3i32 a3netWSendMoveEvent(a3_NetworkingManager* net, a3i32 objID, a3i32 x, a3i32 y);

	a3i32 a3netWSetType(a3_NetworkingManager* net, int type);
#ifdef __cplusplus
}
#endif
#endif

