#ifndef ENGINE_SPRITESHEET
#define ENGINE_SPRITESHEET

#include "Engine/Math/IVector2.h"
#include "Sprite.h"
#include <string>

class SpriteSheet : public Sprite
{
public:
	SpriteSheet();
	SpriteSheet(const std::string& imgPath, const IVector2& _dim);
	SpriteSheet(const std::string& imgPath, const IVector2& _dim, const Vector2& _pos);
	SpriteSheet(const std::string& imgPath, const IVector2& _dim, const Vector2& _pos, const float& _scale);
	SpriteSheet(const int& imgID, const IVector2& _dim);
	SpriteSheet(const int& imgID, const IVector2& _dim, const Vector2& _pos);
	SpriteSheet(const int& imgID, const IVector2& _dim, const Vector2& _pos, const float& _scale);
	
	void Render(const IVector2& sheetCoord) const;
	void RenderRelativeTo(const Vector2& _pos, const IVector2& sheetCoord) const;
	void RenderRelativeTo(const Vector2& _pos, const float& _rot, const IVector2& sheetCoord) const;

private:
	IVector2 dimPxl;
	Vector2 dimPercent;

	void Initialize(const IVector2& _dim);
	void RenderHelper(const IVector2& sheetCoord, const Vector2& posOffset, const float& rotOffset) const;
};

#endif