#include "EventWrapper.h"
#include "NetEvent.h"
#include "MoveEvent.h"
#include "A3_DEMO/a3_Networking/NetworkDataSource.h"
extern "C"
{
	NetEvent* newNetEvent(a3_NetGameMessages type, a3i32 addTime)
	{
		return nullptr;
	}

	NetEvent* newMoveEvent(a3i32 id, a3i32 x, a3i32 y, a3i32 addtime)
	{
		return new MoveEvent(id, x, y, addtime);
	}

	void NetEvent_setTime(NetEvent* nEvent, a3i32 time)
	{
		nEvent->setTime(time);
	}

	a3i32 NetEvent_getTime(NetEvent* nEvent)
	{
		return nEvent->getTime();
	}

	void NetEvent_executeEvent(NetEvent* nEvent)
	{
		nEvent->executeOrder();
	}

	void deleteNetEvent(NetEvent* nEvent)
	{
		delete nEvent;
	}
}