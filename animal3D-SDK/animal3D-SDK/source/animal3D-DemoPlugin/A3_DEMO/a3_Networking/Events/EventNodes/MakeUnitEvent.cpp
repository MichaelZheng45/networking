#include "MakeUnitEvent.h"
#include "A3_DEMO/Game/Game.h"
MakeUnitEvent::MakeUnitEvent(a3i32 objID, a3i32 newX, a3i32 newY, a3i32 addTime) : NetEvent(addTime)
{
	//messageType = ID_GAME_EVENT;
	mObjID = objID;
	x = newX;
	y = newY;
}

void MakeUnitEvent::executeOrder()
{
	a3_Game* gameInstance = a3_Game::getInstance();

	gameInstance->createUnowned(mObjID,x,y);
}