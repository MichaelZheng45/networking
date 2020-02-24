#ifndef EVENTLIST_H
#define EVENTLIST_H

#include "A3_DEMO/a3_Networking/Events/EventNodes/EventWrapper.h"
#ifdef __cplusplus
extern "C"
{
#else	// !__cplusplus
typedef struct EventList			EventList;
#endif	// __cplusplus

struct EventList
{
	EventList* next;

	NetEvent* mEvent;
};
#ifdef __cplusplus
}
#endif	// __cplusplus



#endif // !EVENTLIST_H
