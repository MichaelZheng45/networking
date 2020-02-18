#ifndef MOVEEVENT_H
#define MOVEEVENT_H

#include "NetEvent.h"
#include "Game.h"

class MoveEvent : public NetEvent
{
	public: 
	MoveEvent(int objID, int newX, int newY, int addTime);
	virtual void executeOrder(Game* game, char* message, int bufferSize);

	private:
	int mObjID;
	int x;
	int y;
};

#endif //!MOVEEVENT_H