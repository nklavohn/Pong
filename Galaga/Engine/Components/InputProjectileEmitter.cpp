#include "InputProjectileEmitter.h"

#include "Engine/Engine.h"

InputProjectileEmitter::InputProjectileEmitter(std::unique_ptr<Projectile> _projectile, const float& _cooldown) 
	: ProjectileEmitter(std::move(_projectile), _cooldown)
{

}

InputProjectileEmitter::InputProjectileEmitter(std::unique_ptr<Projectile> _projectile, const float& _cooldown,
	const std::shared_ptr<EntityQueue<Entity>> sQueue)
	: ProjectileEmitter(std::move(_projectile), _cooldown, sQueue)
{
	cooldown = _cooldown;
	remainingTime = cooldown;
}

InputProjectileEmitter::~InputProjectileEmitter()
{

}

void InputProjectileEmitter::Emit(const Vector2& pos, const Vector2& vel, const float& angleRange)
{
	remainingTime -= Engine::GetDeltaTime();

	if (Input() && remainingTime < 0)
	{
		std::shared_ptr<Projectile> newPart = projectile->CloneProjectile();
		newPart->SetPos(pos);
		newPart->SetVel((angleRange > 0) ? RandomizeDir(vel, 10) : vel);
		spawnQueue->Add(newPart);
		remainingTime = cooldown;
	}
}