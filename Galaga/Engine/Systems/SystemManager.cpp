#include "SystemManager.h"

SystemManager::SystemManager()
{

}

SystemManager::~SystemManager()
{

}

void SystemManager::AddSystem(const std::shared_ptr<SystemBase> system)
{
	systems.push_back(system);
}

void SystemManager::DeactivateSystem(const int& id)
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

void SystemManager::ActivateSystem(const int& id)
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

void SystemManager::Update(EntityRegistry& registry)
{
	for (auto& itr : systems)
	{
		itr->Work(registry);
	}
}