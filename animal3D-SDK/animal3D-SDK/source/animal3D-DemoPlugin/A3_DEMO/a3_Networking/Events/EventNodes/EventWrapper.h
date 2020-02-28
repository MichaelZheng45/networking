#ifndef EVENTWRAPPER_H
#define EVENTWRAPPER_H

//https://www.teddy.ch/c++_library_in_c/
#include "animal3D/animal3D.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct NetEvent NetEvent;

NetEvent* newNetEvent(a3_NetGameMessages type, a3i32 addTime);
NetEvent* newMoveEvent(a3i32 id, a3i32 x, a3i32 y, a3i32 addtime);
void NetEvent_setTime(NetEvent* nEvent, a3i32 time);

a3i32 NetEvent_getTime(NetEvent* nEvent);

//pass in game reference
void NetEvent_executeEvent(NetEvent* nEvent);

void deleteNetEvent(NetEvent* nEvent);

#ifdef  __cplusplus
}
#endif // __cplusplus
#endif // !EVENTWRAPPER_H

