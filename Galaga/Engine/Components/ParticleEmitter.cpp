#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter()
{

}

ParticleEmitter::ParticleEmitter(const std::shared_ptr<EntityQueue<Entity>> sQueue) : Spawner(sQueue)
{

}

ParticleEmitter::~ParticleEmitter()
{

}