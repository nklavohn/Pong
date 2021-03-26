#ifndef ENGINE_UPDATER
#define ENGINE_UPDATER

#include "System.h"

class Updater : public SystemID<Updater>
{
public:
	Updater();
	~Updater();

	void Work(EntityRegistry& registry) override;
};

#endif