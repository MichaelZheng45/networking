#include "Game.h"
#include "A3_DEMO/a3_NetworkingManager.h"
a3_Game* a3_Game::instance = 0;

a3_Game* a3_Game::getInstance()
{
	return instance;
}

a3_Game::a3_Game(a3boolean isServer, gameType id, a3i32 nxSize, a3i32 nySize)
{
	server = isServer;
	gameTypeID = id;
	xSize = nxSize;
	ySize = nySize;
	switch (gameTypeID)
	{
	case PUSH_MODE:
		//if server generate units
		if (server)
		{
			for (a3i32 i = 0; i < 20; i++)
			{
				a3i32 xPos = rand() % xSize;
				a3i32 yPos = rand() % ySize;
				ownedUnits[i].xPos;
				ownedUnits[i].yPos;

				ownedUnits[i].xDir = rand() % 7 + (-3);
				ownedUnits[i].yDir = rand() % 7 + (-3);
				ownedUnits[i].active = true;
				moveUnitEventSend(i, xPos, yPos);
			}
		}
		//if not do nothing
		break;
	case SHARING_MODE:
	case COUPLED_MODE:
		// both generate owned units
		for (a3i32 i = 0; i < 20; i++)
		{
			a3i32 xPos = rand() % xSize;
			a3i32 yPos = rand() % ySize;
			ownedUnits[i].xPos;
			ownedUnits[i].yPos;

			ownedUnits[i].xDir = rand() % 7 + (-3);
			ownedUnits[i].yDir = rand() % 7 + (-3);
			ownedUnits[i].active = true;
			moveUnitEventSend(i, xPos, yPos);
		}
		break;
	default:
		break;
	}
}

a3_Game::~a3_Game()
{

}

void a3_Game::runGame()
{
	switch (gameTypeID)
	{
	case PUSH_MODE:
		runNetModePush();
		break;
	case SHARING_MODE:
		runNetModeShared();
		break;
	case COUPLED_MODE:
		runNetModeCoupled();
		break;
	default:
		break;
	}
}

void a3_Game::initNetGame(gameType type, a3boolean isServer, a3i32 xSize, a3i32 ySize)
{
	instance = new a3_Game(isServer, type, xSize, ySize);
}

void a3_Game::runNetModePush()
{
	//is server update units, send unit information
	if (server)
	{
		for (a3i32 i = 0; i < 20; i++)
		{
			ownedUnits[i].xPos += ownedUnits[i].xDir;
			ownedUnits[i].yPos += ownedUnits[i].yDir;

			if (ownedUnits[i].xPos < 0)
			{
				ownedUnits[i].xPos = xSize;
			}
			if (ownedUnits[i].xPos > xSize)
			{
				ownedUnits[i].xPos = 0;
			}
			if (ownedUnits[i].yPos < 0)
			{
				ownedUnits[i].yPos = ySize;
			}
			if (ownedUnits[i].yPos < ySize)
			{
				ownedUnits[i].yPos = 0;
			}

			a3_NetworkingManager* netInstance = a3_NetworkingManager::getInstance();
			netInstance->a3netSendMoveEvent(i, ownedUnits[i].xPos, ownedUnits[i].yPos);
		}
	}
}

void a3_Game::runNetModeShared()
{
	//update owned units, send updated units
	for (a3i32 i = 0; i < 20; i++)
	{
		ownedUnits[i].xPos += ownedUnits[i].xDir;
		ownedUnits[i].yPos += ownedUnits[i].yDir;

		if (ownedUnits[i].xPos < 0)
		{
			ownedUnits[i].xPos = xSize;
		}
		if (ownedUnits[i].xPos > xSize)
		{
			ownedUnits[i].xPos = 0;
		}
		if (ownedUnits[i].yPos < 0)
		{
			ownedUnits[i].yPos = ySize;
		}
		if (ownedUnits[i].yPos < ySize)
		{
			ownedUnits[i].yPos = 0;
		}

		a3_NetworkingManager* netInstance = a3_NetworkingManager::getInstance();
		netInstance->a3netSendMoveEvent(i, ownedUnits[i].xPos, ownedUnits[i].yPos);
	}
}

void a3_Game::runNetModeCoupled()
{
	//update owned units but also check with non owned units
	for (a3i32 i = 0; i < 20; i++)
	{
		ownedUnits[i].xPos += ownedUnits[i].xDir;
		ownedUnits[i].yPos += ownedUnits[i].yDir;

		if (ownedUnits[i].xPos < 0)
		{
			ownedUnits[i].xPos = xSize;
		}
		if (ownedUnits[i].xPos > xSize)
		{
			ownedUnits[i].xPos = 0;
		}
		if (ownedUnits[i].yPos < 0)
		{
			ownedUnits[i].yPos = ySize;
		}
		if (ownedUnits[i].yPos < ySize)
		{
			ownedUnits[i].yPos = 0;
		}

		a3_NetworkingManager* netInstance = a3_NetworkingManager::getInstance();
		netInstance->a3netSendMoveEvent(i, ownedUnits[i].xPos, ownedUnits[i].yPos);
	}
	//sned unit information
}

void a3_Game::moveUnitEventSend(a3i32 id, a3i32 xPos, a3i32 yPos)
{
	a3_NetworkingManager* netInstance = a3_NetworkingManager::getInstance();
	netInstance->a3netSendMoveEvent(id, xPos, yPos);
}


void a3_Game::createUnowned(a3i32 objID, a3i32 newX, a3i32 newY)
{
	unownedUnit[objID].xPos = newX;
	unownedUnit[objID].yPos = newY;
	unownedUnit[objID].active = true;
}

void a3_Game::moveUnit(a3i32 objID, a3i32 newX, a3i32 newY)
{
	unownedUnit[objID].xPos = newX;
	unownedUnit[objID].yPos = newY;
	unownedUnit[objID].active = true;
}
