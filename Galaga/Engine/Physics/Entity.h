#ifndef ENGINE_ENTITY
#define ENGINE_ENTITY

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "CollisionDetector.h"
#include "Engine/Graphics/SpriteSheet.h"

class Entity
{
public:
	bool IsCollidingWith(const Vector2& point) const;
	bool IsCollidingWith(Entity* _cDetector) const;
	
	bool NeedsToBeRemoved() const;
	bool FlagForRemoval(const bool& flag = true);

	Entity();
	Entity(Vector2 _pos);
	~Entity();

	virtual void Move() = 0;
	virtual void Render() const = 0;
	virtual void DebugPhysics() const = 0;

protected:
	//Organization
	bool isFlaggedForRemoval = false;
	int id;

	//Physics
	Vector2 pos;
	Vector2 vel;
	Vector2 accel;
	CollisionDetector* cDetector;
	
	//Graphics
	SpriteSheet spriteSheet;
	IVector2 currentSprite;

	//Private methods
	void SetCollisionDetector(CollisionDetector* _cDetector);
	void SetPos(const Vector2& _pos);
	void SetVel(const Vector2& _vel);
	void SetAccel(const Vector2& _accel);
	CollisionDetector* GetCollisionDetector();

	void DebugPhysicsDefault() const;
};

#endif