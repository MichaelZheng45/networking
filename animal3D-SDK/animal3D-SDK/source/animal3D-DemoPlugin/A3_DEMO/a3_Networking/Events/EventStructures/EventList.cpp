#include "EventList.h"

EventList::EventList(NetEvent* newEvent)
{
	mEvent = newEvent;
	next = nullptr;
}

EventList::~EventList()
{
	delete mEvent;
	delete next;
}