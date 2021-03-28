#include "EntityUpdater.h"

EntityUpdater::EntityUpdater()
{

}

EntityUpdater::~EntityUpdater()
{

}

void EntityUpdater::Work(EntityRegistry& registry)
{
	registry.UpdateEntities();
}