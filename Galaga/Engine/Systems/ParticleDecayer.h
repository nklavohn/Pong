#ifndef ENGINE_PARTICLEDECAYER
#define ENGINE_PARTICLEDECAYER

#include "System.h"

class ParticleDecayer : public System
{
public:
	void Work(EntityRegistry& registry) override;
};

#endif
