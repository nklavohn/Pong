#include "ParticleDecayer.h"

unsigned short ParticleDecayer::ID = 0;

ParticleDecayer::ParticleDecayer()
{

}

ParticleDecayer::~ParticleDecayer()
{

}

void ParticleDecayer::Work(EntityRegistry& registry)
{
	float dt = Engine::GetDeltaTime();
	for (auto& it : registry.particles.entities)
	{
		it.second->Decay();
	}
}