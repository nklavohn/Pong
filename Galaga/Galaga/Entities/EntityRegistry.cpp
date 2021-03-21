#include "EntityRegistry.h"

EntityRegistry::EntityRegistry()
{
	catalog.emplace(ship->id, ship->category);
}

EntityRegistry::~EntityRegistry()
{

}

void EntityRegistry::ProcessSpawnQueue()
{
	while (!spawnQueue->IsEmpty())
	{
		std::shared_ptr<Entity> entity = spawnQueue->Pop();
		switch (entity->category)
		{
		case (Entity::PROJECTILE):
			catalog.emplace(entity->id, Entity::PROJECTILE);
			projectiles.Add(entity->id, entity);
			break;
		case (Entity::PARTICLE):
			catalog.emplace(entity->id, Entity::PARTICLE);
			particles.Add(entity->id, entity);
			break;
		case (Entity::ENEMY):
			catalog.emplace(entity->id, Entity::ENEMY);
			enemies.Add(entity->id, entity);
			break;
		case (Entity::PLAYER):
			std::cout << "Cannot add another player, already have one!" << std::endl;
			break;
		default:
			std::cout << "Adding an undefined entity type to Registry" << std::endl;
			break;
		}
	}
}

std::shared_ptr<Entity> EntityRegistry::GetEntity(const int& id) const
{
	int pool = catalog.at(id);

	switch (pool)
	{
	case (Entity::PROJECTILE):
		return projectiles.GetEntity(id);
	case (Entity::PARTICLE):
		return particles.GetEntity(id);
	case (Entity::ENEMY):
		return enemies.GetEntity(id);
	case (Entity::PLAYER):
		return std::dynamic_pointer_cast<Entity>(ship);
	default:
		std::cout << "tha fuk is happenin' in EntityRegistry?" << std::endl;
		return nullptr;
	}
}