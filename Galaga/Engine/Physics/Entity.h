#ifndef ENGINE_ENTITY
#define ENGINE_ENTITY

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"

class Entity
{
public:
	virtual void Move();
	virtual void Render();

	Entity();
	Entity(Vector2 pos, Vector4 hitbox);
	~Entity();

protected:
	Vector2 pos;
	Vector4 hitbox;
};

#endif