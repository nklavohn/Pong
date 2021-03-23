#include "Spawner.h"

Spawner::Spawner()
{
	spawnQueue = defaultSpawnQueue;
}

Spawner::Spawner(const std::shared_ptr<entity_queue<Entity>> sQueue)
{
	spawnQueue = sQueue;
}

Spawner::~Spawner()
{

}

void Spawner::SetDefaultSpawnQueue(const std::shared_ptr<entity_queue<Entity>> newDefault)
{
	defaultSpawnQueue = newDefault;
}

void Spawner::SetSpawnQueue(const std::shared_ptr<entity_queue<Entity>> sQueue)
{
	spawnQueue = sQueue;
}

void Spawner::Spawn(const std::shared_ptr<Entity> entity)
{
	spawnQueue->Add(entity);
}