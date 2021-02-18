#ifndef ENGINE_SPRITESHEET
#define ENGINE_SPRITESHEET

#include "Engine/Math/IVector.h"
#include "Sprite.h"
#include <string>

class SpriteSheet: public Sprite
{
public:
	SpriteSheet();
	SpriteSheet(string imgPath, IVector _dim);
	SpriteSheet(string imgPath, IVector _dim, Vector _pos);
	SpriteSheet(string imgPath, IVector _dim, Vector _pos, float _scale);
	SpriteSheet(int imgID, IVector _dim);
	SpriteSheet(int imgID, IVector _dim, Vector _pos);
	void RenderSprite(IVector spriteCoord);
	void RenderSpriteRelativeTo(Vector _pos, IVector spriteCoord);
	SpriteSheet(int imgID, IVector _dim, Vector _pos, float _scale);



private:
	IVector dimPxl;
	Vector dimPercent;

	void Initialize(IVector _dim);
	void RenderSpriteHelper(IVector spriteCoord, Vector offset);
};

#endif