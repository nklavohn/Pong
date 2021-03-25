#ifndef ENGINE_SPRITEDOBJECT
#define ENGINE_SPRITEDOBJECT

#include "Engine/Graphics/SpriteSheet.h"
#include "Engine/Math/IVector2.h"

class SpritedObject
{
public:
	SpritedObject(const SpriteSheet& sheet);
	virtual ~SpritedObject();
	 
protected:
	SpriteSheet spriteSheet;
	IVector2 currentSprite;
};

#endif
