#ifndef ENGINE_ENTITYPHYSICSDEBUGGER
#define ENGINE_ENTITYPHYSICSDEBUGGER

#include "ConstSystem.h"

class EntityPhysicsDebugger : public ConstSystem<EntityPhysicsDebugger>
{
public:
	EntityPhysicsDebugger();
	~EntityPhysicsDebugger();

	void Work(const EntityRegistry& registry) const override;
};

#endif
