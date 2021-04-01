#ifndef ENGINE_INPUTPROJECTILEEMITTER
#define ENGINE_INPUTPROJECTILEEMITTER

#include "ProjectileEmitter.h"

class InputProjectileEmitter : public ProjectileEmitter
{
public:
	InputProjectileEmitter(std::unique_ptr<Projectile> _projectile, const float& _cooldown);
	InputProjectileEmitter(std::unique_ptr<Projectile> _projectile, const float& _cooldown, const std::shared_ptr<EntityQueue<Entity>> sQueue);
	virtual ~InputProjectileEmitter();

	virtual bool Input() const = 0;
	void Emit(const Vector2& pos, const Vector2& vel, const float& angleRange) override;
};

#endif
