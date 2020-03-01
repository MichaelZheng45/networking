#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H


#include "animal3D/animal3D.h"

#ifdef __cplusplus
extern "C" {
#endif

void updateGame();
void initGame(a3i32 type, a3boolean isServer, a3i32 xSize, a3i32 ySize); 

//get ownedunit to draw
//get unowned unit to draw
//get ownedunit list
//get unownedunit list
#ifdef  __cplusplus
}
#endif //  __cplusplus
#endif // !GAMEWRAPPER_H