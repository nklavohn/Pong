#ifndef ENGINE_PARTICLEEMITTER
#define ENGINE_PARTICLEEMITTER

#include "Spawner.h"

class ParticleEmitter : public Spawner
{
public:
	ParticleEmitter();
	ParticleEmitter(const std::shared_ptr<entity_queue<Entity>> sQueue);
	~ParticleEmitter();

	virtual void EmitParticles() = 0;
};

#endif
