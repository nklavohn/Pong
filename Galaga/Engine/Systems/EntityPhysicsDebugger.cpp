#include "EntityPhysicsDebugger.h"

EntityPhysicsDebugger::EntityPhysicsDebugger()
{

}

EntityPhysicsDebugger::~EntityPhysicsDebugger()
{

}

void EntityPhysicsDebugger::Work(EntityRegistry& registry)
{
	registry.DebugEntityPhysics();
}