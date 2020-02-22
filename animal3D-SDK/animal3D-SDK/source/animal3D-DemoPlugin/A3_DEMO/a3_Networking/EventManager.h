#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "animal3D/animal3D.h"

#ifdef __cplusplus
extern "C"
{
#else	// !__cplusplus
typedef struct EventManager			EventManager;
#endif	// __cplusplus


	struct EventManager
	{
		int nodeCount;
	};

	a3i32 executeEvent(EventManager* eventMan, char* message, int bufferSize);
	a3boolean addEvent(EventManager* eventMan);

#ifdef __cplusplus
}
#endif	// __cplusplus


#endif // !EVENTMANAGER_H

