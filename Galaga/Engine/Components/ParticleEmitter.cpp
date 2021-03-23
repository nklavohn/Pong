#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter()
{

}

ParticleEmitter::ParticleEmitter(const std::shared_ptr<entity_queue<Entity>> sQueue) : Spawner(sQueue)
{

}

ParticleEmitter::~ParticleEmitter()
{

}