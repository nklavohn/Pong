#include "SpritedObject.h"

SpritedObject::SpritedObject(const SpriteSheet& sheet)
{
	spriteSheet = sheet;
	currentSprite = IVector2::ZERO;
}

SpritedObject::~SpritedObject()
{

}