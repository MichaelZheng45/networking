#include "GameWrapper.h"
#include "Game.h"
#include "A3_DEMO/a3_NetworkingManager.h"
extern "C"
{
	void updateGame()
	{
		a3_NetworkingManager* manager;
		a3netSendMoveEvent(manager, 1,1,1);

		//iterate through game list, and update movement
		//for each movement, send updated movement to server based on mode
	}

	//init game based on mode, do stuff. send owned units through 
}

