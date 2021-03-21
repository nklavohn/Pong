#include "Event.h"

Event::Event() : id(GetNextID())
{

}

Event::~Event()
{

}

int Event::GetNextID()
{
	return ++nextID;
}