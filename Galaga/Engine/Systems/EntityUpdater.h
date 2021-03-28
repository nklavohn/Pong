#ifndef ENGINE_UPDATER
#define ENGINE_UPDATER

#include "System.h"

class EntityUpdater : public System<EntityUpdater>
{
public:
	EntityUpdater();
	~EntityUpdater();

	void Work(EntityRegistry& registry) override;
};

#endif