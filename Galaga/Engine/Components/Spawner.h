#ifndef ENGINE_SPAWNER
#define ENGINE_SPAWNER

#include "Engine/Entities/Entity.h"
#include "Engine/Entities/EntityQueue.h"

#include <memory>
#include <queue>

class Spawner
{
public:
	Spawner();
	Spawner(const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~Spawner();

	void Spawn(const std::shared_ptr<Entity> entity);

	static void SetDefaultSpawnQueue(const std::shared_ptr<EntityQueue<Entity>> newDefault);
	void SetSpawnQueue(const std::shared_ptr<EntityQueue<Entity>> sQueue);

protected:
	std::shared_ptr<EntityQueue<Entity>> spawnQueue = nullptr;

private:
	static std::shared_ptr<EntityQueue<Entity>> defaultSpawnQueue;
};

#endif