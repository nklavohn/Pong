#include "ConstSystem.h"

unsigned short ConstSystemBase::nextID = 0;

ConstSystemBase::ConstSystemBase()
{
	isActive = true;
}

ConstSystemBase::~ConstSystemBase()
{

}

bool ConstSystemBase::IsActive() const
{
	return isActive;
}

void ConstSystemBase::Deactivate()
{
	isActive = false;
}

void ConstSystemBase::Activate()
{
	isActive = true;
}

unsigned short ConstSystemBase::GetNextID()
{
	return ++nextID;
}