#include "EventManager.h"

EventManager::EventManager()
{
	nodeCount = 0;
	mHead = nullptr;
}

EventManager::~EventManager()
{
	delete mHead;
}

a3i32 EventManager::executeEvent()
{
	//find current
	EventList* current = mHead;

	//if head is not empty
	if (current == nullptr)
	{
		return 0;
	}

	//reset head to the next one
	mHead = mHead->next;

	//get event
	current->mEvent->executeOrder();
	nodeCount--;
	current->next = nullptr;
	delete current;
	//remove event
	//delete current;
	return 0;
}

//befoere adding event the new event must be created as new
a3boolean EventManager::addEvent(NetEvent* newEvent)
{
	//iterate through eventlist, then check time stamp,
	//if the next node's time stamp is greater than it then insert there
	bool inserted = false;
	EventList* current = mHead;

	//if the list is empty create new head
	if (mHead == nullptr)
	{
		inserted = true;
		EventList* newEventList = new EventList(newEvent);
		mHead = newEventList;
	
		nodeCount++;
		return true;
	}

	//if the head is higher than the new event, create new head
	if (current->mEvent->getTime() >= newEvent->getTime())
	{
		inserted = true;
		EventList* newEventList = new EventList(newEvent);
		EventList* newHead = newEventList;

		newHead->next = mHead;
		mHead = newHead;

		nodeCount++;
		return true;
	}

	//iterate until inserted
	while (!inserted)
	{
		//if at the end of the list
		if (current->next == nullptr)
		{
			//curent is last in line
			inserted = true;
			EventList* newEventList = new EventList(newEvent);
			current->next = newEventList;
			nodeCount++;
			return true;
		}
		//if the next node has a greater time stamp than current event
		else if (current->next->mEvent->getTime() >= newEvent->getTime())
		{
			//inserted and relink the nodes
			inserted = true;
			EventList* newEventList = new EventList(newEvent);
			EventList* newNode = newEventList;
			newNode->next = current->next;
			current->next = newNode;

			nodeCount++;
			return true;
		}
		else
		{
			//iterate next
			current = current->next;
		}
	}

	return false;
}

a3i32 EventManager::getNodeCount()
{
	return nodeCount;
}

