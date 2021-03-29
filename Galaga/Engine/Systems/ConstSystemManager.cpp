#include "ConstSystemManager.h"

ConstSystemManager::ConstSystemManager()
{

}

ConstSystemManager::~ConstSystemManager()
{

}

void ConstSystemManager::AddSystem(const std::shared_ptr<ConstSystemBase> system)
{
	systems.push_back(system);
}

void ConstSystemManager::DeactivateSystem(const int& id)
{
	for (auto& itr : systems)
	{
		if (itr->GetID() == id)
		{
			itr->Deactivate();
			break;
		}
	}
}

void ConstSystemManager::ActivateSystem(const int& id)
{
	for (auto& itr : systems)
	{
		if (itr->GetID() == id)
		{
			itr->Activate();
			break;
		}
	}
}

void ConstSystemManager::Manage(const EntityRegistry& registry) const
{
	for (auto& itr : systems)
	{
		itr->Work(registry);
	}
}