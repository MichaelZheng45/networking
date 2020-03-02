#include "A3_DEMO/Game/Game.h"
#include "InitGameEvent.h"

InitGameEvent::InitGameEvent(a3i32 newGameID, a3i32 addTime, a3i32 xSize, a3i32 ySize) : NetEvent( addTime)
{
	messageType = ID_GAME_EVENT;
	type = newGameID;
	xS = xSize;
	yS = ySize;
}

void InitGameEvent::executeOrder()
{
	a3_Game* gameInstance = a3_Game::getInstance();
	gameInstance = new a3_Game(false, static_cast<gameType>(type), xS, yS);
}