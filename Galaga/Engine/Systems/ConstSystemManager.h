#ifndef ENGINE_CONSTSYSTEMMANAGER
#define ENGINE_CONSTSYSTEMMANAGER

#include "Engine/Entities/EntityRegistry.h"
#include "Engine/Systems/ConstSystem.h"

#include <memory>
#include <vector>

class ConstSystemManager
{
public:
	ConstSystemManager();
	~ConstSystemManager();

	void Manage(const EntityRegistry& registry) const;
	void AddSystem(const std::shared_ptr<ConstSystemBase> system);
	void DeactivateSystem(const int& system);
	void ActivateSystem(const int& system);

private:
	std::vector<std::shared_ptr<ConstSystemBase>> systems = std::vector<std::shared_ptr<ConstSystemBase>>();
};

#endif
