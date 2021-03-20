#ifndef SPACEGAME_ENTITYREGISTRY
#define SPACEGAME_ENTITYREGISTRY

#include "Engine/Entities/EntityPool.h"
#include "Engine/Entities/Particle.h"
#include "Engine/Entities/Enemy.h"
#include "Engine/Entities/Projectile.h"

#include <memory>

class EntityRegistry
{
public:
	EntityRegistry();
	~EntityRegistry();

	void SpawnEntity(std::shared_ptr<Entity> entity);

	entity_pool<Particle> particles = entity_pool<Particle>();
	entity_pool<Enemy> enemies = entity_pool<Enemy>();
	entity_pool<Projectile> projectiles = entity_pool<Projectile>();
	entity_pool<Entity> justSpawned = entity_pool<Entity>();
};

#endif