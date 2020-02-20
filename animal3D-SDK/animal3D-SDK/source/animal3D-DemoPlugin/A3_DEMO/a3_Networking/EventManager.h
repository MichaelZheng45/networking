#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

class EventManager
{
public:
	EventManager();
	~EventManager();

	int executeEvent(char* message, int bufferSize);
	bool addEvent();
	int getListLength();

private:
	int nodeCount;
};

#endif // !EVENTMANAGER_H

