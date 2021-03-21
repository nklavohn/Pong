#ifndef SPACEGAME_ENTITYREGISTRY
#define SPACEGAME_ENTITYREGISTRY

#include "Engine/Entities/EntityPool.h"
#include "Engine/Entities/Particle.h"
#include "Engine/Entities/Enemy.h"
#include "Engine/Entities/Projectile.h"
#include "Engine/Entities/EntityQueue.h"
#include "Galaga/Entities/Spaceship.h"

#include <memory>
#include <queue>

class EntityRegistry
{
public:
	EntityRegistry();
	~EntityRegistry();

	std::unordered_map<int, int> catalog;

	std::shared_ptr<Spaceship> ship = std::make_shared<Spaceship>();
	entity_pool<Enemy> enemies = entity_pool<Enemy>();
	entity_pool<Projectile> projectiles = entity_pool<Projectile>();
	entity_pool<Particle> particles = entity_pool<Particle>();
	
	std::shared_ptr<entity_queue<Entity>> spawnQueue = std::shared_ptr<entity_queue<Entity>>();

	void ProcessSpawnQueue();
	void ProcessDeletions();
	std::shared_ptr<Entity> GetEntity(const int& id) const;
};

#endif