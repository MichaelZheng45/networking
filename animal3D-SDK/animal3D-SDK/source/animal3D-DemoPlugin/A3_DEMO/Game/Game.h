
#ifndef GAME_H
#define GAME_H

#include "animal3D/animal3D.h"
#include "Unit.h"

#ifdef  __cplusplus

enum gameType
{	
	PUSH_MODE,
	SHARING_MODE,
	COUPLED_MODE
};

class a3_Game
{
public:
	static a3_Game* getInstance();
	
	void runGame();

	static void initNetGame(gameType type, a3boolean isServer, a3i32 xSize, a3i32 ySize);


	void runNetModePush();
	void runNetModeShared();
	void runNetModeCoupled();

	void moveUnitEventSend(a3i32 id, a3i32 xPos, a3i32 yPos);
	void createUnowned(a3i32 objID, a3i32 newX, a3i32 newY);
	void moveUnit(a3i32 objID, a3i32 newX, a3i32 newY);

	a3_Game(a3boolean isServer, gameType id, a3i32 xSize, a3i32 ySize);
	~a3_Game();

	private:


	static a3_Game* instance;

	a3i32 xSize;
	a3i32 ySize;
	a3boolean server;
	gameType gameTypeID;
	a3_Unit ownedUnits[20];
	a3_Unit unownedUnit[20];
};

#else
	typedef struct a3_Game a3_Game;
#endif
#endif // !GAME_H
