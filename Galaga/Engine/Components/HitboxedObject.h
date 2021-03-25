#ifndef ENGINE_HITBOXOWNER
#define ENGINE_HITBOXOWNER

#include "Engine/Physics/Hitbox.h"

#include <memory>

class HitboxedObject
{
public:
	HitboxedObject(std::unique_ptr<Hitbox> _hitbox);
	virtual ~HitboxedObject();

protected:
	std::unique_ptr<Hitbox> hitbox;

	Hitbox* GetHitbox() const;
	void SetHitbox(std::unique_ptr<Hitbox> _hitbox);

	bool IsCollidingWith(const Vector2& point) const;
	bool IsCollidingWith(HitboxedObject* _cDetector) const;
};

#endif
