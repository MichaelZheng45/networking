#ifndef  MAKEUNITEVENT_H
#define MAKEUNITYEVENT_H

#include "NetEvent.h"
#pragma pack(push, 1)
class MakeUnitEvent : public NetEvent
{
	public: 
	MakeUnitEvent(a3i32 objID, a3i32 newX, a3i32 newY, a3i32 addTime);
	virtual void executeOrder();

	private:
		unsigned char messageType;
		a3i32 mObjID;
		a3i32 x;
		a3i32 y;
};
#pragma pack(pop)
#endif // ! MAKEUNITEVENT_H
