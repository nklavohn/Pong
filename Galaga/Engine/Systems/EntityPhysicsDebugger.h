#ifndef ENGINE_ENTITYPHYSICSDEBUGGER
#define ENGINE_ENTITYPHYSICSDEBUGGER

#include "System.h"

class EntityPhysicsDebugger : public System<EntityPhysicsDebugger>
{
	EntityPhysicsDebugger();
	~EntityPhysicsDebugger();

	void Work(EntityRegistry& registry) override;
};

#endif
