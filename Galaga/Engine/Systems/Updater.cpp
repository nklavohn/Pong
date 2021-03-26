#include "Updater.h"

Updater::Updater()
{

}

Updater::~Updater()
{

}

void Updater::Work(EntityRegistry& registry)
{
	registry.UpdateEntities();
}