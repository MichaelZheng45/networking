#ifndef  MAKEUNITEVENT_H
#define MAKEUNITYEVENT_H

#include "NetEvent.h"
class MakeUnitEvent : public NetEvent
{
	public: 
	MakeUnitEvent(a3i32 objID, a3i32 newX, a3i32 newY, a3i32 addTime);
	virtual void executeOrder();

	private:
		a3_NetGameMessages messageType;
		a3i32 mObjID;
		a3i32 x;
		a3i32 y;
};

#endif // ! MAKEUNITEVENT_H
