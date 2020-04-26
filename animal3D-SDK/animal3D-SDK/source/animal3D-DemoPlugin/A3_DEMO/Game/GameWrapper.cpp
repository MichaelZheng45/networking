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

	void updateGame(a3f64 tick)
	{
		a3_Game* gameIns = a3_Game::getInstance();
		if (gameIns != 0)
		{
			gameIns->runGame(tick);
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

	a3boolean unownedUnitActive(a3i32 objID)
	{
		a3_Unit unit = a3_Game::getInstance()->unownedUnit[objID];
		return unit.active;
	}

	a3i32 getUnownedUnitX(a3i32 objID)
	{
		return a3_Game::getInstance()->unownedUnit[objID].position.xVal;
	}

	a3i32 getUnownedUnitY(a3i32 objID)
	{
		return a3_Game::getInstance()->unownedUnit[objID].position.yVal;
	}

	a3i32 getOwnedList()
	{
		return 20;
	}
	a3boolean ownedUnitActive(a3i32 objID)
	{
		a3_Unit unit = a3_Game::getInstance()->ownedUnits[objID];
		return unit.active;
	}

	a3i32 getOwnedUnitX(a3i32 objID)
	{
		return a3_Game::getInstance()->ownedUnits[objID].position.xVal;
	}

	a3i32 getOwnedUnitY(a3i32 objID)
	{
		return a3_Game::getInstance()->ownedUnits[objID].position.yVal;
	}
}

