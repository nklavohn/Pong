#include "System.h"

unsigned short System::nextID = 0;

System::System()
{
	isActive = true;
}

System::~System()
{

}

bool System::IsActive() const
{
	return isActive;
}

void System::Deactivate()
{
	isActive = false;
}

void System::Activate()
{
	isActive = true;
}

unsigned short System::GetNextID()
{
	return ++nextID;
}