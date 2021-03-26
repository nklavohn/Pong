#ifndef ENGINE_PARTICLEEMITTER
#define ENGINE_PARTICLEEMITTER

#include "Spawner.h"

class ParticleEmitter : public Spawner
{
public:
	ParticleEmitter();
	ParticleEmitter(const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~ParticleEmitter();

	virtual void EmitParticles(const Vector2& pos, const Vector2& vel) = 0;
};

#endif
