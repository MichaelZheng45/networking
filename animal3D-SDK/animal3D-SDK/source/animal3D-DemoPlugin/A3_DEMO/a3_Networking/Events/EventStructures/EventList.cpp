#include "EventList.h"

EventList::EventList(NetEvent* newEvent)
{
	mEvent = newEvent;
}

EventList::~EventList()
{
	delete mEvent;
	delete next;
}