#ifndef MOVEEVENT_H
#define MOVEEVENT_H

#include "NetEvent.h"

#pragma pack( 1)
class MoveEvent : public NetEvent
{
	public: 
		MoveEvent();
		MoveEvent(a3i32 objID, a3i32 newX, a3i32 newY, a3i32 addTime);
		virtual void executeOrder();

	private:
		unsigned char messageType;
		a3i32 mObjID;
		a3i32 x;
		a3i32 y;
};

#endif //!MOVEEVENT_H