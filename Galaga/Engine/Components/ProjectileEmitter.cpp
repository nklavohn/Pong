#include "ProjectileEmitter.h"

ProjectileEmitter::ProjectileEmitter(std::unique_ptr<Projectile> _projectile, const float& _cooldown) : Emitter(_cooldown), projectile(std::move(_projectile))
{

}

ProjectileEmitter::ProjectileEmitter(std::unique_ptr<Projectile> _projectile, const float& _cooldown,
	const std::shared_ptr<EntityQueue<Entity>> sQueue)
	: Emitter(_cooldown, sQueue), projectile(std::move(_projectile))
{
	
}

ProjectileEmitter::~ProjectileEmitter()
{

}