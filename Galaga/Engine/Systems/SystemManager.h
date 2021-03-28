#ifndef	ENGINE_SYSTEMMANAGER
#define ENGINE_SYSTEMMANAGER

#include "System.h"

#include <vector>

class SystemManager
{
public:
	SystemManager();
	~SystemManager();

	void Update(EntityRegistry& registry);
	void AddSystem(const std::shared_ptr<SystemBase> system);
	void DeactivateSystem(const int& system);
	void ActivateSystem(const int& system);

private:
	std::vector<std::shared_ptr<SystemBase>> systems = std::vector<std::shared_ptr<SystemBase>>();
};

#endif
