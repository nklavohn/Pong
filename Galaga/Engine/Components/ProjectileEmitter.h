#ifndef ENGINE_PROJECTILEEMITTER
#define ENGINE_PROJECTILEEMITTER

#include "Emitter.h"
#include "Engine/Entities/Projectile.h"

class ProjectileEmitter : public Emitter
{
public:
	ProjectileEmitter(std::unique_ptr<Projectile> _projectile, const float& _cooldown);
	ProjectileEmitter(std::unique_ptr<Projectile> _projectile, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~ProjectileEmitter();

	virtual void Emit(const Vector2& pos, const Vector2& vel, const float& angleRange) override = 0;

protected:
	std::unique_ptr<Projectile> projectile;

};

#endif
