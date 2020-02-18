#ifndef EVENTLIST_H
#define EVENTLIST_H

#include "A3_DEMO/a3_Networking/Events/EventNodes/NetEvent.h"

class EventList
{
	public: 
		EventList(NetEvent* newEvent);
		~EventList();

		NetEvent* getEvent();
		EventList* getNext();
		void setNext(EventList* newNext);

	private:
		EventList* next;

		NetEvent* mEvent;
};
#endif // !EVENTLIST_H
