#include "GameWrapper.h"
#include "Game.h"
#include "A3_DEMO/a3_NetworkingManager.h"
extern "C"
{
	void updateGame()
	{
		a3_Game* gameIns = a3_Game::getInstance();
		if (gameIns != 0)
		{
			gameIns->runGame();
		}
	}

	//init game based on mode, do stuff. send owned units through 
	void initGame(a3i32 type, a3boolean isServer, a3i32 xSize, a3i32 ySize)
	{
		gameType gType = static_cast<gameType>(type);

		a3_Game::initNetGame(gType, isServer, xSize, ySize);
	}
}

