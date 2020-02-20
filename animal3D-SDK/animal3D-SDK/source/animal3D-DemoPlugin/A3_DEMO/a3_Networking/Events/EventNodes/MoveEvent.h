#ifndef MOVEEVENT_H
#define MOVEEVENT_H

#include "NetEvent.h"

class MoveEvent : public NetEvent
{
	public: 
		MoveEvent(a3i32 objID, a3i32 newX, a3i32 newY, a3i32 addTime);
		virtual void executeOrder( char* message, int bufferSize);

	private:
		a3i32 mObjID;
		a3i32 x;
		a3i32 y;
};

#endif //!MOVEEVENT_H