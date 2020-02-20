#ifndef  NETEVENT_H
#define EVENT_H

#include "A3_DEMO/a3_Networking/NetworkDataSource.h"
#include "A3_DEMO/Game/Game.h"
#include "RakNet/RakPeerInterface.h"
#include "RakNet/MessageIdentifiers.h"
#include "RakNet/RakNetTypes.h"
#include "RakNet/BitStream.h"
#include "RakNet/GetTime.h"
class NetEvent
{
	public:
	NetEvent(a3_NetGameMessages type, a3i32 addTime);
	~NetEvent();

	virtual void executeOrder(a3_Game* game, char* message, int bufferSize) = 0;
	float getTime() {return timeStamp;}
	void setTime(a3i32 time) {timeStamp = time;}
	
	protected:

	a3_NetGameMessages messageType;
	a3i32 timeStamp;
};

#endif // ! NETEVENT_H
