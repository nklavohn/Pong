#ifndef ENGINE_ENTITYRENDERER
#define ENGINE_ENTITYRENDERER

#include "System.h"

class EntityRenderer : public System<EntityRenderer>
{
public:
	EntityRenderer();
	~EntityRenderer();

	void Work(EntityRegistry& registry) override;
};

#endif
