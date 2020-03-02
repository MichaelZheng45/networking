#include "NetEvent.h"

NetEvent::NetEvent(a3i32 addTime)
{
	timeStamp = addTime;
}

NetEvent::~NetEvent()
{

}

void NetEvent::executeOrder()
{

}

a3i32 NetEvent::getTime()
{
	return timeStamp;
}

void NetEvent::setTime(a3i32 time)
{
	timeStamp = time;
}