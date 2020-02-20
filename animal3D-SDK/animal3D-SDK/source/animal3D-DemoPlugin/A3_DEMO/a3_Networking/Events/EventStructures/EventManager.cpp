#include "EventManager.h"

EventManager::EventManager()
{
	mHead = nullptr;
	nodeCount = 0;
}

EventManager::~EventManager()
{
	while (mHead != nullptr)
	{
		EventList* current = mHead;
		mHead = mHead->getNext();

		delete current;
	}
}

int EventManager::executeEvent(char* message, int bufferSize)
{
	//find current
	EventList* current = mHead;

	//if head is not empty
	if (current == nullptr)
	{
		return -1;
	}

	//reset head to the next one
	mHead = mHead->getNext();

	//get event
	current->getEvent()->executeOrder(message, bufferSize);

	//remove event
	delete current;
	return 0;
}

//befoere adding event the new event must be created as new
bool EventManager::addEvent(NetEvent* newEvent)
{
	//iterate through eventlist, then check time stamp,
	//if the next node's time stamp is greater than it then insert there
	bool inserted = false;

	EventList* current = mHead;

	//if the list is empty create new head
	if (mHead == nullptr)
	{
		inserted = true;
		mHead = new EventList(newEvent);
	
		nodeCount++;
		return true;
	}

	//if the head is higher than the new event, create new head
	if (mHead->getEvent()->getTime() >= newEvent->getTime())
	{
		inserted = true;
		EventList* newHead = new EventList(newEvent);

		newHead->setNext(mHead);
		mHead = newHead;

		nodeCount++;
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
			current->setNext(new EventList(newEvent));
		}
		//if the next node has a greater time stamp than current event
		else if (current->getNext()->getEvent()->getTime() >= newEvent->getTime())
		{
			//inserted and relink the nodes
			inserted = true;

			EventList* newNode = new EventList(newEvent);
			newNode->setNext(current->getNext());
			current->setNext(newNode);

			nodeCount++;
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

int EventManager::getListLength()
{
	return nodeCount;
}
