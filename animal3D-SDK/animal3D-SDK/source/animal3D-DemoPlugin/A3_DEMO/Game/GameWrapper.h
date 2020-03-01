#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H


#include "animal3D/animal3D.h"

#ifdef __cplusplus
extern "C" {
#endif

void updateGame();
void initGame(int type, a3boolean isServer); 

//get ownedunit to draw
//get unowned unit to draw
//get ownedunit list
//get unownedunit list
#ifdef  __cplusplus
}
#endif //  __cplusplus
#endif // !GAMEWRAPPER_H