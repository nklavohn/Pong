#include "EntityRegistry.h"

EntityRegistry::EntityRegistry()
{
	
}

EntityRegistry::~EntityRegistry()
{

}

void EntityRegistry::DefinePlayer(const std::shared_ptr<Player> _player)
{
	player = _player;
}

void EntityRegistry::ApplySpawnQueue()
{
	//TODO replace with loop over enum so this doesn't need to be updated every time a new entity type is added
	while (!spawnQueue->IsEmpty())
	{
		std::shared_ptr<Entity> entity = spawnQueue->Pop();
		switch (entity->category)
		{
		case (Entity::PROJECTILE):
			catalog.emplace(entity->id, Entity::PROJECTILE);
			projectiles.Add(entity->id, entity);
			entity->SetDeleteQueue(deleteQueue);
			break;
		case (Entity::PARTICLE):
			catalog.emplace(entity->id, Entity::PARTICLE);
			particles.Add(entity->id, entity);
			entity->SetDeleteQueue(deleteQueue);
			break;
		case (Entity::ENEMY):
			catalog.emplace(entity->id, Entity::ENEMY);
			enemies.Add(entity->id, entity);
			entity->SetDeleteQueue(deleteQueue);
			break;
		case (Entity::PLAYER):
			std::cout << "Players can only be added during screen initialization!" << std::endl;
			break;
		default:
			std::cout << "Adding an undefined entity type to Registry" << std::endl;
			break;
		}
	}
}

void EntityRegistry::ApplyDeleteQueue()
{
	while (!deleteQueue->empty())
	{
		int id = deleteQueue->front();
		int category = catalog.at(id);

		switch (category)
		{
		case (Entity::PROJECTILE):
			projectiles.Remove(id);
			break;
		case (Entity::PARTICLE):
			particles.Remove(id);
			break;
		case (Entity::ENEMY):
			enemies.Remove(id);
			break;
		case (Entity::PLAYER):
			std::cout << "Player just got deleted from EntityRegistry::ApplyDeleteQueue()" << std::endl;
			break;
		default:
			std::cout << "Hit default in EntityRegistry::ApplyDeleteQueue()" << std::endl;
			break;
		}

		catalog.erase(id);
		deleteQueue->pop();
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
		std::cout << "Make sure this works correctly! (EntityRegistry)" << std::endl;
		return player;
	default:
		std::cout << "tha fuk is happenin' in EntityRegistry?" << std::endl;
		return nullptr;
	}
}

void EntityRegistry::UpdateEntities()
{
	player->Update();
	enemies.Update();
	projectiles.Update();
	particles.Update();
}

void EntityRegistry::RenderEntities() const
{
	player->Render();
	enemies.Render();
	projectiles.Render();
	particles.Render();
}

void EntityRegistry::DebugEntityPhysics() const
{
	player->DebugPhysics();
	enemies.DebugPhysics();
	projectiles.DebugPhysics();
	particles.DebugPhysics();
}