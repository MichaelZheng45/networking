
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
	static void createInstance(bool isServer, gameType id, a3i32 nxSize, a3i32 nySize);
	void runGame(a3f64 tick);

	static void initNetGame(gameType type, a3boolean isServer, a3i32 xSize, a3i32 ySize);


	void runNetModePush();
	void runNetModeShared();
	void runNetModeCoupled(a3f64 tick);

	void moveUnitEventSend(a3_Unit unit);
	void createUnowned(a3i32 objID, a3f32 newX, a3f32 newY, a3f32 newXDir, a3f32 newYDir, a3f32 velocity);
	void moveUnit(a3i32 objID, a3f32 newX, a3f32 newY, a3f32 newXDir, a3f32 newYDir, a3f32 velocity);

	a3_Game(a3boolean isServer, gameType id, a3i32 xSize, a3i32 ySize);
	~a3_Game();

	a3_Unit ownedUnits[20];
	a3_Unit unownedUnit[20];

	private:

	static a3_Game* instance;

	a3i32 xSize;
	a3i32 ySize;
	a3boolean server;
	gameType gameTypeID;

	a3i32 iterator = 0;
};

#else
	typedef struct a3_Game a3_Game;
#endif
#endif // !GAME_H
