#include "GameWrapper.h"
#include "Game.h"
#include "A3_DEMO/a3_NetworkingManager.h"
extern "C"
{
	void updateGame()
	{
		//a3_NetworkingManager* manager;
		//manager->a3netSendMoveEvent(1, 1, 1);

		//iterate through game list, and update movement
		//for each movement, send updated movement to server based on mode
	}

	//init game based on mode, do stuff. send owned units through 
	void initGame(int type, a3boolean isServer)
	{
		gameType gType = static_cast<gameType>(type);

		a3_Game* gameIns = a3_Game::getInstance();
		switch (gType)
		{
		case PUSH_MODE:
			break;
		case SHARING_MODE:
			break;
		case COUPLED_MODE:
			break;
		default:
			break;
		}
	}
}

