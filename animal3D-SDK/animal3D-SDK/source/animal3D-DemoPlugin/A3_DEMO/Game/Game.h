
#ifndef GAME_H
#define GAME_H

#include "animal3D/animal3D.h"
#include "Unit.h"

#ifdef __cplusplus
extern "C"
{
#else	//! __cplusplus
	typedef struct a3_Game				a3_Game;
#endif // __ cplusplus

	enum gameType
	{	
		PUSH_MODE,
		SHARING_MODE,
		COUPLED_MODE
	};

	struct a3_Game
	{
		a3i32 gameID;

		

		a3_Unit ownedUnits[20];
		a3_Unit unownedUnit[20];
	};

	void run(a3_Game* game);

	void initNetModeOne(a3_Game* game);
	void initNetModeTwo(a3_Game* game);
	void initNetModeThree(a3_Game* game);

	void runNetModeOne(a3_Game* game);
	void runNetModeTwo(a3_Game* game);
	void runNetModeThree(a3_Game* game);

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif // !GAME_H
