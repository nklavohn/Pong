#ifndef ENGINE_ENTITYPOOL
#define ENGINE_ENTITYPOOL
#include <vector>
#include "Entity.h"
#include <set>
#include <queue>
#include <memory>

class EntityPool
{
public:
	std::vector<std::unique_ptr<Entity>> entities{};

	EntityPool();
	~EntityPool();

	void Render() const;
	void Update();

private:
	
};

#endif