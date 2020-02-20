#include "MoveEvent.h"



MoveEvent::MoveEvent(a3i32 objID, a3i32 newX, a3i32 newY, a3i32 addTime) : NetEvent(ID_GAME_EVENT, addTime)
{
	mObjID = objID;
	x = newX;
	y = newY;
}

void MoveEvent::executeOrder(char* message, int bufferSize)
{
	printf("Executing order move event on unit: " + mObjID );
	printf(", timestamp: " + timeStamp);
}