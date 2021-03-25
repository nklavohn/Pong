#ifndef ENGINE_SYSTEM
#define ENGINE_SYSTEM

#include "Engine/Entities/EntityRegistry.h"
#include "Engine/Engine.h"

class System
{
public:
	virtual void Work(EntityRegistry& registry) = 0;
};

#endif
