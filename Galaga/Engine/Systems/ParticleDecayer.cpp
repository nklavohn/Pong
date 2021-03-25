#include "ParticleDecayer.h"

void ParticleDecayer::Work(EntityRegistry& registry)
{
	float dt = Engine::GetDeltaTime();
	for (auto& it : registry.particles.entities)
	{
		it.second->Decay();
	}
}