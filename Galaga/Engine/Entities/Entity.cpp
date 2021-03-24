#include "Entity.h"
#include "Engine/Graphics/ShapeRenderer.h"

int Entity::NEXT_ID = 0;

Entity::Entity(const enum Category _category) : id(GetNextID()), category(_category)
{
	spriteSheet = SpriteSheet();
	Initialize();
}

Entity::Entity(const enum Category _category, const SpriteSheet& _spriteSheet) : id(GetNextID()), category(_category)
{
	spriteSheet = _spriteSheet;
	Initialize();
}

Entity::~Entity()
{

}

void Entity::Initialize()
{
	
	currentSprite = IVector2::ZERO;

	
}

int Entity::GetNextID()
{
	return NEXT_ID++;
}
