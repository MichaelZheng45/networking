#include "MoveEvent.h"
#include "A3_DEMO/Game/Game.h"

MoveEvent::MoveEvent() : NetEvent(0)
{

}

MoveEvent::MoveEvent(a3i32 objID, a3f32 newX, a3f32 newY, a3i32 addTime, a3f32 newXDir, a3f32 newYDir, a3f32 nVelocity) : NetEvent( addTime)
{	
	messageType = ID_GAME_MOVE_EVENT;
	mObjID = objID;
	x = newX;
	y = newY;
	xDir = newXDir;
	yDir = newYDir;
	velocity = nVelocity;
}

void MoveEvent::executeOrder()
{

	a3_Game* gameInstance = a3_Game::getInstance();
	if (gameInstance != 0 || gameInstance != nullptr)
	{
		gameInstance->moveUnit(mObjID, x, y,xDir,yDir,velocity);
	}
	
}