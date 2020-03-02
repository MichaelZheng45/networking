#ifndef  INITGAMEEVENT_H
#define INITGAMEEVENT_H

#include "NetEvent.h"
#pragma pack(push, 1)
class InitGameEvent : public NetEvent
{
	public: 
	InitGameEvent(a3i32 newGameID, a3i32 addTime, a3i32 xSize, a3i32 ySize);
	
	virtual void executeOrder();

	private:
		unsigned char messageType;
	a3i32 type;
	a3i32 xS;
	a3i32 yS;
};
#pragma pack(pop)

#endif // ! INITGAMEEVENT_H
