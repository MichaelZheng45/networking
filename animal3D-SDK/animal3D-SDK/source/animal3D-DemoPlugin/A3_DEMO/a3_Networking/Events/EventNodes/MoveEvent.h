#ifndef MOVEEVENT_H
#define MOVEEVENT_H

#include "NetEvent.h"

#pragma pack( 1)
class MoveEvent : public NetEvent
{
	public: 
		MoveEvent();
		MoveEvent(a3i32 objID, a3f32 newX, a3f32 newY, a3i32 addTime, a3f32 newXDir,a3f32 newYDir, a3f32 velocity);
		virtual void executeOrder();

	private:
		unsigned char messageType;
		a3i32 mObjID;
		a3f32 x;
		a3f32 y;
		a3f32 xDir;
		a3f32 yDir;
		a3f32 velocity;
};

#endif //!MOVEEVENT_H