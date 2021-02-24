#ifndef ENGINE_ENTITY
#define ENGINE_ENTITY

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "CollisionDetector.h"

class Entity
{
public:
	bool IsCollidingWith(Vector2 point);
	bool IsCollidingWith(CollisionDetector* _cDetector);
	CollisionDetector* GetCollisionDetector();

	Entity();
	Entity(Vector2 _pos, CollisionDetector& _hitbox);
	~Entity();

	virtual void Move() = 0;
	virtual void Render() = 0;
	virtual void Debug() = 0;

protected:
	Vector2 pos;  //in world coordinates
	CollisionDetector* cDetector;  //in world coordinates

};

#endif