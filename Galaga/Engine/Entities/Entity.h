#ifndef ENGINE_ENTITY
#define ENGINE_ENTITY

#include "Engine/Math/IVector2.h"
#include "Engine/Graphics/SpriteSheet.h"
#include "Engine/Components/RegistryMember.h"

#include <memory>

class Entity : public RegistryMember
{
public:
	const enum Category {
		PLAYER,
		ENEMY,
		PROJECTILE,
		PARTICLE,
		MAX
	};

	Entity(const enum Category _category);
	Entity(const enum Category _category, const SpriteSheet& _spriteSheet);
	virtual ~Entity();

	virtual void Update() = 0;
	virtual void Render() const = 0;
	virtual std::shared_ptr<Entity> CloneEntity() const = 0;

	const int id;
	const enum Category category;
	
protected:
	static int GetNextID();	
	
	//Graphics
	SpriteSheet spriteSheet;
	IVector2 currentSprite;

	void AddSelfToDeleteQueue() override;

private:
	static int NEXT_ID;

	void Initialize();
};

#endif