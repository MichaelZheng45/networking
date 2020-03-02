#include "GameWrapper.h"
#include "Game.h"
#include "A3_DEMO/a3_NetworkingManager.h"
extern "C"
{

	a3boolean checkInit()
	{
		a3_Game* gameIns = a3_Game::getInstance();
		if (gameIns != 0)
		{
			return true;
		}
		return false;
	}

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

		a3_NetworkingManager::getInstance()->a3netInitGameEvent(type, xSize, ySize);
		a3_Game::initNetGame(gType, isServer, xSize, ySize);
	}

	a3i32 getUnownedList()
	{
		return 20;
	}

	a3boolean getUnownedUnit(a3i32 objID, a3i32 xPos, a3i32 yPos)
	{
		a3_Unit unit = a3_Game::getInstance()->ownedUnits[objID];
		xPos = unit.xPos;
		yPos = unit.yPos;
		return unit.active;
	}

	a3i32 getOwnedList()
	{
		return 20;
	}
	a3boolean getOwnedUnit(a3i32 objID, a3i32 xPos, a3i32 yPos)
	{
		a3_Unit unit = a3_Game::getInstance()->ownedUnits[objID];
		xPos = unit.xPos;
		yPos = unit.yPos;
		return unit.active;
	}
}

