#ifndef SPACEGAME_ENTITYREGISTRY
#define SPACEGAME_ENTITYREGISTRY

#include "EntityPool.h"
#include "Particle.h"
#include "Enemy.h"
#include "Projectile.h"
#include "EntityQueue.h"
#include "Player.h"

#include <memory>
#include <queue>

class EntityRegistry
{
public:
	EntityRegistry();
	~EntityRegistry();

	//bureaucratic shit
	std::unordered_map<int, int> catalog;
	std::shared_ptr<entity_queue<Entity>> spawnQueue;
	std::shared_ptr<std::queue<int>> deleteQueue;

	//collections to hold all the entities
	std::shared_ptr<Player> player;
	entity_pool<Enemy> enemies;
	entity_pool<Projectile> projectiles;
	entity_pool<Particle> particles;

	//functions
	void DefinePlayer(const std::shared_ptr<Player> _player);
	void ApplySpawnQueue();
	void ApplyDeleteQueue();
	std::shared_ptr<Entity> GetEntity(const int& id) const;
};

#endif