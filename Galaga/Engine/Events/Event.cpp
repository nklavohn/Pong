#include "Event.h"

int Event::nextID = 0;

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