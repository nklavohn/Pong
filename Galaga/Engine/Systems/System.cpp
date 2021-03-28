#include "System.h"

unsigned short SystemBase::nextID = 0;

SystemBase::SystemBase()
{
	isActive = true;
}

SystemBase::~SystemBase()
{

}

bool SystemBase::IsActive() const
{
	return isActive;
}

void SystemBase::Deactivate()
{
	isActive = false;
}

void SystemBase::Activate()
{
	isActive = true;
}

unsigned short SystemBase::GetNextID()
{
	return ++nextID;
}