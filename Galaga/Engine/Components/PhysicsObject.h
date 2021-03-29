#ifndef ENGINE_PHYSICSOBJECT
#define ENGINE_PHYSICSOBJECT

#include "Engine/Math/Vector2.h"
#include "HitboxedObject.h"
#include "Engine/Physics/TranslationalState.h"

class PhysicsObject : public HitboxedObject
{
public:
	PhysicsObject(std::unique_ptr<Hitbox> _hitbox);
	PhysicsObject(std::unique_ptr<Hitbox> _hitbox, const TranslationalState& _tState);
	virtual ~PhysicsObject();

	virtual void DebugPhysics() const = 0;

	void SetPos(const Vector2& _pos);
	void SetVel(const Vector2& _vel);

protected:
	TranslationalState tState;

	void ApplyPhysics();
	void DebugPhysicsDefault() const;
};

#endif