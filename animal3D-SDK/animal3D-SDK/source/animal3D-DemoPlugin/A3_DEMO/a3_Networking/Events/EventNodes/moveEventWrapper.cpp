#include "moveEventWrapper.h"
#include "MoveEvent.h"
#include "A3_DEMO/a3_Networking/NetworkDataSource.h"

extern "C"
{
	MoveEvent* newMoveEventCreate(a3_NetGameMessages type, a3i32 id, a3i32 x, a3i32 y, a3i32 addtime)
	{
		return nullptr;
	}

	void executeEvent(MoveEvent* nEvent)
	{
		nEvent->executeOrder();
	}
}


