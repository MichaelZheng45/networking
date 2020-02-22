#include "EventManager.h"

a3i32 executeEvent(EventManager* eventMan, char* message, int bufferSize)
{
	//find current
	EventList* current = eventMan->mHead;

	//if head is not empty
	if (current == nullptr)
	{
		return -1;
	}

	//reset head to the next one
	eventMan->mHead = eventMan->mHead->getNext();

	//get event
	current->getEvent()->executeOrder(message, bufferSize);
	eventMan->nodeCount--;
	//remove event
	//delete current;
	return 0;
}

//befoere adding event the new event must be created as new
a3boolean addEvent(EventManager* eventMan, NetEvent* newEvent)
{
	//iterate through eventlist, then check time stamp,
	//if the next node's time stamp is greater than it then insert there
	bool inserted = false;

	EventList* current = eventMan->mHead;

	//if the list is empty create new head
	if (eventMan->mHead == nullptr)
	{
		inserted = true;
		eventMan->mHead =  &EventList(newEvent);
	
		eventMan->nodeCount++;
		return true;
	}

	//if the head is higher than the new event, create new head
	if (eventMan->mHead->getEvent()->getTime() >= newEvent->getTime())
	{
		inserted = true;
		EventList* newHead = &EventList(newEvent);

		newHead->setNext(eventMan->mHead);
		eventMan->mHead = newHead;

		eventMan->nodeCount++;
		return true;
	}

	//iterate until inserted
	while (!inserted)
	{
		//if at the end of the list
		if (current->getNext() == nullptr)
		{
			//curent is last in line
			inserted = true;
			current->setNext(&EventList(newEvent));
		}
		//if the next node has a greater time stamp than current event
		else if (current->getNext()->getEvent()->getTime() >= newEvent->getTime())
		{
			//inserted and relink the nodes
			inserted = true;

			EventList* newNode = &EventList(newEvent);
			newNode->setNext(current->getNext());
			current->setNext(newNode);

			eventMan->nodeCount++;
			return true;
		}
		else
		{
			//iterate next
			current = current->getNext();
		}
	}

	return false;
}

