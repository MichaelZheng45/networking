
#ifndef GAME_H
#define GAME_H

#include "animal3D/animal3D.h"

#ifdef __cplusplus
extern "C"
{
#else	//! __cplusplus
	typedef struct a3_Game				a3_Game;
#endif // __ cplusplus

	struct a3_Game
	{
		a3i32 gameID;
	};

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif // !GAME_H
