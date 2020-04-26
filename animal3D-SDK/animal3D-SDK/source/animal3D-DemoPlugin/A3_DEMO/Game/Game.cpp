#include "Game.h"
#include "A3_DEMO/a3_NetworkingManager.h"
#include <time.h>
a3_Game* a3_Game::instance = 0;

a3_Game* a3_Game::getInstance()
{
	return instance;
}

void a3_Game::createInstance(bool isServer, gameType id, a3i32 nxSize,a3i32 nySize)
{
	instance = new a3_Game(false, id, nxSize, nySize);
}

a3_Game::a3_Game(a3boolean isServer, gameType id, a3i32 nxSize, a3i32 nySize)
{
	if (isServer)
	{
		std::srand(16412);
	}
	else
	{
		srand(81635415);
	}

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
				ownedUnits[i].unitID = i;
				a3i32 xPos = rand() % xSize;
				a3i32 yPos = rand() % ySize;
				ownedUnits[i].position = makeVector(xPos, yPos);

				a3i32 xDir = rand() % 7 + (-3);
				a3i32 yDir = rand() % 7 + (-3);
				ownedUnits[i].velocity = magnitude(makeVector(xDir,yDir));
				ownedUnits[i].direction = normalize(makeVector(xDir, yDir));
				ownedUnits[i].active = true;
				moveUnitEventSend(ownedUnits[i]);
			}
		}
		//if not do nothing
		break;
	case SHARING_MODE:
	case COUPLED_MODE:
		// both generate owned units
		for (a3i32 i = 0; i < 20; i++)
		{
			ownedUnits[i].unitID = i;
			a3i32 xPos = rand() % xSize;
			a3i32 yPos = rand() % ySize;
			ownedUnits[i].position = makeVector(xPos, yPos);
		
			a3i32 xDir = rand() % 7 + (-3);
			a3i32 yDir = rand() % 7 + (-3);
			ownedUnits[i].velocity = magnitude(makeVector(xDir, yDir));
			ownedUnits[i].direction = normalize(makeVector(xDir, yDir));
			ownedUnits[i].active = true;
			moveUnitEventSend(ownedUnits[i]);
		}
		break;
	default:
		break;
	}
}

a3_Game::~a3_Game()
{

}

void a3_Game::runGame(a3f64 tick)
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
		runNetModeCoupled(tick * 33);
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
			updateUnit(ownedUnits[i], 0);
			
			if (ownedUnits[i].position.xVal < 0)
			{
				ownedUnits[i].position.xVal = xSize;
			}
			if (ownedUnits[i].position.xVal > xSize)
			{
				ownedUnits[i].position.xVal = 0;
			}
			if (ownedUnits[i].position.yVal < 0)
			{
				ownedUnits[i].position.yVal = ySize;
			}
			if (ownedUnits[i].position.yVal > ySize)
			{
				ownedUnits[i].position.yVal = 0;
			}

			moveUnitEventSend(ownedUnits[i]);
		}
	}
}

void a3_Game::runNetModeShared()
{
	//update owned units, send updated units
	for (a3i32 i = 0; i < 20; i++)
	{
		updateUnit(ownedUnits[i], 0);

		if (ownedUnits[i].position.xVal < 0)
		{
			ownedUnits[i].position.xVal = xSize;
		}
		if (ownedUnits[i].position.xVal > xSize)
		{
			ownedUnits[i].position.xVal = 0;
		}
		if (ownedUnits[i].position.yVal < 0)
		{
			ownedUnits[i].position.yVal = ySize;
		}
		if (ownedUnits[i].position.yVal > ySize)
		{
			ownedUnits[i].position.yVal = 0;
		}

		moveUnitEventSend(ownedUnits[i]);
	}
}

void a3_Game::runNetModeCoupled(a3f64 tick)
{
	a3f32 timeDiff = tick;
	//update owned units but also check with non owned units
	for (a3i32 i = 0; i < 20; i++)
	{
		updateUnit(ownedUnits[i], timeDiff);

		if (ownedUnits[i].position.xVal < 0)
		{
			ownedUnits[i].position.xVal = xSize;
		}
		if (ownedUnits[i].position.xVal > xSize)
		{
			ownedUnits[i].position.xVal = 0;
		}
		if (ownedUnits[i].position.yVal < 0)
		{
			ownedUnits[i].position.yVal = ySize;
		}
		if (ownedUnits[i].position.yVal > ySize)
		{
			ownedUnits[i].position.yVal = 0;
		}

		for (int j = 0; j < 20; j++)
		{
			vectorsTwo diff = subtract(ownedUnits[i].position, unownedUnit[j].position);
			//for each unowned unit, check for collision
			if (magnitude(diff) < 20)
			{
				ownedUnits[i].direction = normalize(diff);
			}
		}

		for (int k = 0; k < 20; k++)
		{
			vectorsTwo diff = subtract(ownedUnits[i].position, ownedUnits[k].position);
			//for each unowned unit, check for collision
			if (magnitude(diff) < 20 && i != k)
			{
				ownedUnits[i].direction = normalize(diff);
			}
		}

		//remove this
		//moveUnitEventSend(ownedUnits[i]);
	}

	//send move event but only a select few
	for (int i = 0; i < 2; i++)
	{
		moveUnitEventSend(ownedUnits[iterator]);
		iterator++;
		if (iterator >= 20)
		{
			iterator = 0;
		}
	}

	//iterate through unownedlist
	for (int i = 0; i < 20; i++)
	{
		//if the unit has not been updated, self update
		if (unownedUnit[i].updatedThisFrame)
		{
			unownedUnit[i].updatedThisFrame = false;
		}
		else
		{
			updateUnit(unownedUnit[i], timeDiff);
		}
	}
	
}

void a3_Game::moveUnitEventSend(a3_Unit unit)
{
	a3_NetworkingManager* netInstance = a3_NetworkingManager::getInstance();
	netInstance->a3netSendMoveEvent(unit.unitID, unit.position.xVal, unit.position.yVal, unit.direction.xVal, unit.direction.yVal, unit.velocity);
}


void a3_Game::createUnowned(a3i32 objID, a3f32 newX, a3f32 newY, a3f32 newXDir, a3f32 newYDir, a3f32 velocity)
{
	unownedUnit[objID].position.xVal = newX;
	unownedUnit[objID].position.yVal = newY;
	unownedUnit[objID].active = true;
	unownedUnit[objID].updatedThisFrame = true;
	unownedUnit[objID].direction.xVal = newXDir;
	unownedUnit[objID].direction.yVal = newYDir;
	unownedUnit[objID].velocity = velocity;
}

void a3_Game::moveUnit(a3i32 objID, a3f32 newX, a3f32 newY, a3f32 newXDir, a3f32 newYDir, a3f32 velocity)
{
	if (this != nullptr)
	{
		unownedUnit[objID].position.xVal = newX;
		unownedUnit[objID].position.yVal = newY;
		unownedUnit[objID].active = true;
		unownedUnit[objID].updatedThisFrame = true;     
		unownedUnit[objID].direction.xVal = newXDir;
		unownedUnit[objID].direction.yVal = newYDir;
		unownedUnit[objID].velocity = velocity;
	}
}
