#ifndef ENGINE_ENTITY
#define ENGINE_ENTITY

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Hitbox.h"

class Entity
{
public:
	bool IsCollidingWith(Vector2 point, bool inclusive = false);
	bool IsCollidingWith(Vector4 box, bool inclusive = false);
	Hitbox GetHitbox();

	Entity();
	Entity(Vector2 _pos, Vector2 hitboxCenter, Vector2 hitboxDim);
	Entity(Vector2 _pos, Vector4 _hitbox);
	Entity(Vector2 _pos, Hitbox _hitbox);
	~Entity();

	virtual void Move() = 0;
	virtual void Render() = 0;
	virtual void Debug() = 0;

protected:
	Vector2 pos;  //in world coordinates
	Hitbox hitbox;  //in world coordinates
};

#endif