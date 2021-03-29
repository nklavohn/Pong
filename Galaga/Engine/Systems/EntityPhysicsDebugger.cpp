#include "EntityPhysicsDebugger.h"

EntityPhysicsDebugger::EntityPhysicsDebugger()
{

}

EntityPhysicsDebugger::~EntityPhysicsDebugger()
{

}

void EntityPhysicsDebugger::Work(const EntityRegistry& registry) const
{
	registry.DebugEntityPhysics();
}