#include "NetEvent.h"

NetEvent::NetEvent(a3_NetGameMessages type, a3i32 addTime)
{
	timeStamp = addTime;
	messageType = type;
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