#include "NetEvent.h"

NetEvent::NetEvent(a3_NetGameMessages type, a3i32 addTime)
{
	timeStamp = addTime;
	messageType = type;
}

NetEvent::~NetEvent()
{

}

void NetEvent::executeOrder(char* message, int bufferSize)
{

}