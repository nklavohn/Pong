#ifndef ENGINE_PARTICLEDECAYER
#define ENGINE_PARTICLEDECAYER

#include "System.h"

class ParticleDecayer : public SystemID<ParticleDecayer>
{
public:
	ParticleDecayer();
	~ParticleDecayer();

	void Work(EntityRegistry& registry) override;
};

#endif
