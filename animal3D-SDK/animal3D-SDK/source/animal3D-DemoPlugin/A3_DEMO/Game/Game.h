
#ifndef GAME_H
#define GAME_H

#include "animal3D/animal3D.h"
#include "Unit.h"

enum gameType
{	
	PUSH_MODE,
	SHARING_MODE,
	COUPLED_MODE
};

class a3_Game
{
	private:
	a3i32 gameID;
	a3_Unit ownedUnits[20];
	a3_Unit unownedUnit[20];

	public: 
		void run(a3_Game* game);

		void initNetModeOne();
		void initNetModeTwo();
		void initNetModeThree();

		void runNetModeOne();
		void runNetModeTwo();
		void runNetModeThree();
};

#endif // !GAME_H
