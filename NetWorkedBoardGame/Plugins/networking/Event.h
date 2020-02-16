#ifndef EVENT_H
#define EVENT_H

enum eventType
{
	COLOR_EVENT,
	DIRECTION_EVENT,
	SPEED_EVENT,
	MESSAGE_EVENT
};

class Event
{
public:
	Event();
	~Event();

	virtual void executeOrder(char* message) = 0;
	eventType getType() {return type;}
	float getTime() {return timeStamp;}
private:
	eventType type;
	float timeStamp;
};

#endif // !EVENT_H