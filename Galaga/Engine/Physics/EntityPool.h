#ifndef ENGINE_ENTITYPOOL
#define ENGINE_ENTITYPOOL
#include <vector>
#include "Entity.h"
#include <set>
#include <queue>

class EntityPool
{
public:
	std::vector<Entity*> entities{};

	EntityPool();
	~EntityPool();

	void Render() const;
	void Update();

private:
	
};

#endif