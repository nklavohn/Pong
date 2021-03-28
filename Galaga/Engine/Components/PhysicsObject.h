#ifndef ENGINE_PHYSICSOBJECT
#define ENGINE_PHYSICSOBJECT

#include "Engine/Math/Vector2.h"
#include "HitboxedObject.h"
#include "Engine/Physics/TranslationalState2.h"

class PhysicsObject : public HitboxedObject
{
public:
	PhysicsObject(std::unique_ptr<Hitbox> _hitbox);
	PhysicsObject(std::unique_ptr<Hitbox> _hitbox, const TranslationalState2& _tState);
	virtual ~PhysicsObject();

	virtual void DebugPhysics() const = 0;

	void SetPos(const Vector2& _pos);
	void SetVel(const Vector2& _vel);

protected:
	TranslationalState2 tState;

	void ApplyPhysics();
	void DebugPhysicsDefault() const;
};

#endif