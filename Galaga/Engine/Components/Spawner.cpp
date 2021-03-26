#include "Spawner.h"

std::shared_ptr<EntityQueue<Entity>> Spawner::defaultSpawnQueue = nullptr;

Spawner::Spawner()
{
	spawnQueue = defaultSpawnQueue;
}

Spawner::Spawner(const std::shared_ptr<EntityQueue<Entity>> sQueue)
{
	spawnQueue = sQueue;
}

Spawner::~Spawner()
{

}

void Spawner::SetDefaultSpawnQueue(const std::shared_ptr<EntityQueue<Entity>> newDefault)
{
	defaultSpawnQueue = newDefault;
}

void Spawner::SetSpawnQueue(const std::shared_ptr<EntityQueue<Entity>> sQueue)
{
	spawnQueue = sQueue;
}

void Spawner::Spawn(const std::shared_ptr<Entity> entity)
{
	spawnQueue->Add(entity);
}