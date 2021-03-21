#ifndef	ENGINE_EVENTREGISTRY
#define ENGINE_EVENTREGISTRY

#include "Event.h"

#include <memory>
#include <queue>

class EventRegistry
{
public:
	EventRegistry();
	~EventRegistry();

	void AddEvent(const Event& event);
	std::unique_ptr<Event> GetNextEvent();
	bool IsEmtpy() const;

private:
	std::queue<std::unique_ptr<Event>> events;
};

#endif