#ifndef  NETEVENT_H
#define EVENT_H

#include "NetworkDataSource.h"
#include "Game.h"

class NetEvent
{
	public:
	NetEvent(a3_NetGameMessages type, int addTime);
	~NetEvent();

	virtual void executeOrder(Game* game, char* message, int bufferSize) = 0;
	float getTime() {return timeStamp;}
	void setTime(int time) {timeStamp = time;}
	
	private:

	a3_NetGameMessages messageType;
	int timeStamp;
};

#endif // ! NETEVENT_H
