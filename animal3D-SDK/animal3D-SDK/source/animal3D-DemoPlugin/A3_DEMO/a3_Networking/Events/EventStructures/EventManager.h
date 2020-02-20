#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "EventList.h"

class EventManager
{
	public:
		EventManager();	
		~EventManager();

		int executeEvent(a3_Game* game, char* message, int bufferSize);
		bool addEvent(NetEvent* newEvent);
		int getListLength();

	private:

	EventList* mHead;
	int nodeCount;
};

#endif // !EVENTMANAGER_H

