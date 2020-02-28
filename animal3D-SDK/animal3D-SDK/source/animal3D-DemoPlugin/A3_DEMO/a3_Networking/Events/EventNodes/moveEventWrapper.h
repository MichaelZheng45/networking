#ifndef MOVEEVENTWRAPPER_H
#define MOVEEVENTWRAPPER_H

#include "animal3D/animal3D.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct MoveEvent MoveEvent;

	MoveEvent* newMoveEventCreate(a3_NetGameMessages type,a3i32 id, a3i32 x, a3i32 y, a3i32 addtime);
	void executeMoveEvent(MoveEvent* nEvent);
#ifdef __cplusplus
}
#endif // !__cplusplus
#endif // !MOVEEVENTWRAPPER_H
