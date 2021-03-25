#ifndef ENGINE_PHYSICSOBJECT
#define ENGINE_PHYSICSOBJECT

#include "Engine/Math/Vector2.h"
#include "HitboxedObject.h"

class PhysicsObject : public HitboxedObject
{
public:
	PhysicsObject(std::unique_ptr<Hitbox> _hitbox);
	virtual ~PhysicsObject();

	virtual void DebugPhysics() const = 0;

	void SetPos(const Vector2& _pos);
	void SetVel(const Vector2& _vel);
	void SetAccel(const Vector2& _accel);

protected:
	Vector2 prevPos;
	Vector2 vel;
	Vector2 accel;
	float speed;
	float maxSpeed;
	float rot;
	float rotSpeed;

	void ApplyPhysics();
	void DebugPhysicsDefault() const;
};

#endif