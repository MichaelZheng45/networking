#include "EventList.h"

EventList::EventList(NetEvent* newEvent)
{
	mEvent = newEvent;
}

EventList::~EventList()
{
	delete mEvent;
}

NetEvent* EventList::getEvent()
{
	return mEvent;
}

EventList* EventList::getNext()
{
	return next;
}

void EventList::setNext(EventList* newNext)
{
	next = newNext;
}

