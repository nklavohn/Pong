#ifndef ENGINE_ENTITY
#define ENGINE_ENTITY

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Physics/Hitbox.h"
#include "Engine/Graphics/SpriteSheet.h"
#include <memory>

class Entity
{
public:
	const enum Category {
		PLAYER,
		ENEMY,
		PROJECTILE,
		PARTICLE
	};

	bool IsCollidingWith(const Vector2& point) const;
	bool IsCollidingWith(Entity* _cDetector) const;
	
	bool IsFlaggedForRemoval() const;
	void FlagForRemoval(const bool& flag = true);

	Entity();
	Entity(const enum Category _category);
	Entity(const enum Category _category, const SpriteSheet& _spriteSheet);
	~Entity();

	virtual void Move() = 0;
	virtual void Render() const = 0;
	virtual void DebugPhysics() const = 0;

	
	
protected:
	static int GetNextID();

	//Organization
	bool isFlaggedForRemoval = false;
	enum Category category;
	int id;

	//Physics
	Vector2 prevPos;
	Vector2 vel;
	Vector2 accel;
	float speed;
	float maxSpeed;
	float rot;
	float rotSpeed;
	Hitbox* hitbox;
	
	//Graphics
	SpriteSheet spriteSheet;
	IVector2 currentSprite;

	//Private methods
	void SetHitbox(Hitbox* _hitbox);
	void SetPos(const Vector2& _pos);
	void SetVel(const Vector2& _vel);
	void SetAccel(const Vector2& _accel);
	Hitbox* GetHitbox();
	void DebugPhysicsDefault() const;

private:
	static int NEXT_ID;
	void Initialize();
};

#endif