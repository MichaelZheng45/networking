
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

	void initNetModeOne();
	void initNetModeTwo();
	void initNetModeThree();

	void runNetModeOne();
	void runNetModeTwo();
	void runNetModeThree();

	private:
	a3_Game();
	~a3_Game();

	static a3_Game* instance;

	a3i32 gameID;
	a3_Unit ownedUnits[20];
	a3_Unit unownedUnit[20];
};

#else
	typedef struct a3_Game a3_Game;
#endif
#endif // !GAME_H
