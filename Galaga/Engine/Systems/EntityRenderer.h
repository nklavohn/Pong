#ifndef ENGINE_ENTITYRENDERER
#define ENGINE_ENTITYRENDERER

#include "ConstSystem.h"

class EntityRenderer : public ConstSystem<EntityRenderer>
{
public:
	EntityRenderer();
	~EntityRenderer();

	void Work(const EntityRegistry& registry) const override;
};

#endif
