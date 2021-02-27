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
	Entity(Vector2 _pos);
	~Entity();

	virtual void Move() = 0;
	virtual void Render() const = 0;
	virtual void Debug() const = 0;

protected:
	Vector2 pos;  //in world coordinates
	Vector2 vel;
	CollisionDetector* cDetector;  //in world coordinates

	void SetCollisionDetector(CollisionDetector* _cDetector);
	void SetPos(const Vector2& _pos);
	void SetVel(const Vector2& _vel);
	

};

#endif