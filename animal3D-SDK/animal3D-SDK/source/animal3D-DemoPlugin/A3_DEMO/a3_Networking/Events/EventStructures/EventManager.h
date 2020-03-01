#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "animal3D/animal3D.h"
#include "EventList.h"
#include "A3_DEMO/a3_Networking/Events/EventNodes/MoveEvent.h"
#include "A3_DEMO/a3_Networking/Events/EventNodes/NetEvent.h"

class EventManager
{
public:
	EventManager();
	~EventManager();

	a3i32 executeEvent();
	a3boolean addEvent(NetEvent* newEvent);
	a3i32 getNodeCount();
private:

	EventList* mHead;
	a3i32 nodeCount;
};
#endif // !EVENTMANAGER_H 