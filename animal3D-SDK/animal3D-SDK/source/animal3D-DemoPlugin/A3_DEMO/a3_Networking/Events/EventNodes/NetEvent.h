#ifndef NETEVENT_H
#define	NETEVENT_H

#include "animal3D/animal3D.h"
#include "A3_DEMO/a3_Networking/NetworkDataSource.h"
#pragma pack(push, 1)
class NetEvent
{
	public:
	NetEvent(a3i32 addTime);
	~NetEvent();

	virtual void executeOrder() = 0;
	a3i32 getTime();
	void setTime(a3i32 time) ;

	protected:
	a3i32 timeStamp;
};



#endif // ! NETEVENT_H
#pragma pack(pop)
