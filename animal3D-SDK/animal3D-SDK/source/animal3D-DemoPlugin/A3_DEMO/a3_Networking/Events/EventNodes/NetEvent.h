#ifndef NETEVENT_H
#define	NETEVENT_H

#include "animal3D/animal3D.h"
#include "A3_DEMO/a3_Networking/NetworkDataSource.h"

class NetEvent
{
	public:
	NetEvent(a3i32 addTime, a3_NetGameMessages type);
	~NetEvent();

	virtual void executeOrder() = 0;
	a3i32 getTime();
	void setTime(a3i32 time) ;

	protected:
	a3_NetGameMessages messageType;
	a3i32 timeStamp;
};



#endif // ! NETEVENT_H
