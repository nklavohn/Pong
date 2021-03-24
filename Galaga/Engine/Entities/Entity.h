#ifndef ENGINE_ENTITY
#define ENGINE_ENTITY

#include "Engine/Math/IVector2.h"
#include "Engine/Graphics/SpriteSheet.h"
#include "Engine/Components/RegistryMember.h"

#include <memory>

class Entity : public RegistryMember
{
public:
	static const enum Category {
		PLAYER,
		ENEMY,
		PROJECTILE,
		PARTICLE
	};

	Entity(const enum Category _category);
	Entity(const enum Category _category, const SpriteSheet& _spriteSheet);
	~Entity();

	virtual void Move() = 0;
	virtual void Render() const = 0;
	
	auto clone() const { return std::unique_ptr<Entity>(clone_impl()); }
	auto cloneToShared() const { return std::shared_ptr<Entity>(clone_impl()); }

	const int id;
	const enum Category category;
	
protected:
	static int GetNextID();	
	
	//Graphics
	SpriteSheet spriteSheet;
	IVector2 currentSprite;

	virtual Entity* clone_impl() const = 0;

private:
	static int NEXT_ID;

	void Initialize();
};

#endif