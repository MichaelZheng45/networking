#ifndef  NETEVENT_H
#define EVENT_H


#include "animal3D/animal3D.h"

#include "RakNet/BitStream.h"
#include "A3_DEMO/a3_Networking/NetworkDataSource.h"

#ifdef __cplusplus
extern "C"
{
#else	// !__cplusplus
typedef struct NetEvent			NetEvent;
#endif	// __cplusplus


struct NetEvent
{
	a3boolean it;
};


#ifdef __cplusplus
}
#endif	// __cplusplus


struct NetEvent
{
	public:
	NetEvent(a3_NetGameMessages type, a3i32 addTime);
	~NetEvent();

	virtual void executeOrder( char* message, int bufferSize) = 0;
	float getTime() {return timeStamp;}
	void setTime(a3i32 time) {timeStamp = time;}

	protected:

	a3_NetGameMessages messageType;
	a3i32 timeStamp;
};



#endif // ! NETEVENT_H
