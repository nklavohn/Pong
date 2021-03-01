#ifndef ENGINE_ENTITYPOOL
#define ENGINE_ENTITYPOOL
#include <vector>
#include "Entity.h"

class EntityPool
{
public:
	std::vector<Entity*> entities{};

	EntityPool();
	~EntityPool();

	void Render() const;
	void Update();
};

#endif