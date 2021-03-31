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
	std::unordered_map<int, int> catalog = std::unordered_map<int, int>();
	std::shared_ptr<EntityQueue<Entity>> spawnQueue = std::make_shared<EntityQueue<Entity>>();
	std::shared_ptr<std::queue<int>> deleteQueue = std::make_shared<std::queue<int>>();

	//collections to hold all the entities
	//TODO generate these as pointers, pointed to by the EntityEnum, created dynamically so no additional upkeep needs to occur here
	std::shared_ptr<Player> player;
	EntityPool<Enemy> enemies;
	EntityPool<Projectile> projectiles;
	EntityPool<Particle> particles;

	//functions
	void DefinePlayer(const std::shared_ptr<Player> _player);
	void ApplySpawnQueue();
	void ApplyDeleteQueue();
	std::shared_ptr<Entity> GetEntity(const int& id) const;

	void UpdateEntities();
	void RenderEntities() const;
	void DebugEntityPhysics() const;
};

#endif