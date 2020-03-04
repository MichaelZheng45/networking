#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H


#include "animal3D/animal3D.h"

#ifdef __cplusplus
extern "C" {
#endif

a3boolean checkInit();
void updateGame();
void initGame(a3i32 type, a3boolean isServer, a3i32 xSize, a3i32 ySize); 

a3i32 getUnownedList();
a3boolean unownedUnitActive(a3i32 objID);
a3i32 getUnownedUnitX(a3i32 objID);
a3i32 getUnownedUnitY(a3i32 objID);

a3i32 getOwnedList();
a3boolean ownedUnitActive(a3i32 objID);
a3i32 getOwnedUnitX(a3i32 objID);
a3i32 getOwnedUnitY(a3i32 objID);
//get ownedunit to draw
//get unowned unit to draw
//get ownedunit list
//get unownedunit list
#ifdef  __cplusplus
}
#endif //  __cplusplus
#endif // !GAMEWRAPPER_H