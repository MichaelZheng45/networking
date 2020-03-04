#include "MoveEvent.h"
#include "A3_DEMO/Game/Game.h"

MoveEvent::MoveEvent() : NetEvent(0)
{

}

MoveEvent::MoveEvent(a3i32 objID, a3i32 newX, a3i32 newY, a3i32 addTime) : NetEvent( addTime)
{	
	messageType = ID_GAME_MOVE_EVENT;
	mObjID = objID;
	x = newX;
	y = newY;
}

void MoveEvent::executeOrder()
{

	a3_Game* gameInstance = a3_Game::getInstance();
	if (gameInstance != 0 || gameInstance != nullptr)
	{
		gameInstance->moveUnit(mObjID, x, y);
	}
	
}