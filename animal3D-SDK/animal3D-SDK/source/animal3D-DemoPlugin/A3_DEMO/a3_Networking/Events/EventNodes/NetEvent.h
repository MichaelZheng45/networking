#ifndef  NETEVENT_H
#define EVENT_H


#include "animal3D/animal3D.h"


#include "A3_DEMO/a3_Networking/NetworkDataSource.h"

class NetEvent
{
	public:
	NetEvent(a3_NetGameMessages type, a3i32 addTime);
	~NetEvent();

	virtual void executeOrder() = 0;
	float getTime() {return timeStamp;}
	void setTime(a3i32 time) {timeStamp = time;}

	protected:

	a3_NetGameMessages messageType;
	a3i32 timeStamp;
};



#endif // ! NETEVENT_H
