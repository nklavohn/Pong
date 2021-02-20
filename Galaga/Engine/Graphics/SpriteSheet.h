#ifndef ENGINE_SPRITESHEET
#define ENGINE_SPRITESHEET

#include "Engine/Math/IVector2.h"
#include "Sprite.h"
#include <string>

class SpriteSheet : public Sprite
{
public:
	SpriteSheet();
	SpriteSheet(string imgPath, IVector2 _dim);
	SpriteSheet(string imgPath, IVector2 _dim, Vector2 _pos);
	SpriteSheet(string imgPath, IVector2 _dim, Vector2 _pos, float _scale);
	SpriteSheet(int imgID, IVector2 _dim);
	SpriteSheet(int imgID, IVector2 _dim, Vector2 _pos);
	void RenderSprite(IVector2 sheetCoord);
	void RenderSpriteRelativeTo(Vector2 _pos, IVector2 sheetCoord);
	SpriteSheet(int imgID, IVector2 _dim, Vector2 _pos, float _scale);



private:
	IVector2 dimPxl;
	Vector2 dimPercent;

	void Initialize(IVector2 _dim);
	void RenderSpriteHelper(IVector2 sheetCoord, Vector2 offset);
};

#endif