#include "MoveEvent.h"

MoveEvent::MoveEvent(int objID, int newX, int newY, int addTime) : NetEvent(EVENT_1, addTime)
{
	mObjID = objID;
	x = newX;
	y = newY;
}

void MoveEvent::executeOrder(Game* game, char* message, int bufferSize)
{

}