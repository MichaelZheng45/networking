#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H


#include "animal3D/animal3D.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct a3_Game a3_Game;

a3_Game* newA3_Game();

static a3_Game* getA3_Game();

void updateGame();
void initGame(gameType type, a3boolean isServer); 

//get ownedunit to draw
//get unowned unit to draw
//get ownedunit list
//get unownedunit list
#ifdef  __cplusplus
}
#endif //  __cplusplus
#endif // !GAMEWRAPPER_H