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
	void AddSystem(const std::shared_ptr<System> system);
	void DeactivateSystem(const int& system);
	void ActivateSystem(const int& system);

private:
	std::vector<std::shared_ptr<System>> systems = std::vector<std::shared_ptr<System>>();
};

#endif
