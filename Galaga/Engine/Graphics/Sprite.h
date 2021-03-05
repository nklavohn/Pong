#ifndef ENGINE_SPRITE
#define ENGINE_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/Camera.h"

#include <iostream>
#include <string>

class Sprite {

public:
	Sprite();
	Sprite(const std::string& imgPath);
	Sprite(const std::string& imgPath, const Vector2& _pos);
	Sprite(const std::string& imgPath, const Vector2& _pos, const float& _scale);
	Sprite(const int& imgID);
	Sprite(const int& imgID, const Vector2& _pos);
	Sprite(const int& imgID, const Vector2& _pos, const float& _scale);
	~Sprite();

	void Render() const;
	void RenderRelativeTo(const Vector2& _pos) const;
	void RenderRelativeTo(const Vector2& _pos, const float& _rot) const;

	void SetPos(const float& x, const float& y);
	void SetPos(const Vector2& v);
	void SetRot(const float& _rot);
	void AddRot(const float& _rot);
	void SetScale(const float& xy);
	void SetScale(const float& x, const float& y);
	void SetScale(const Vector2& v);
	void SetRotCenter(const Vector2& _rotCenter);

	void SetInterpolationFunction(const int& _interp);

	float GetWidth(bool scaled=true) const;
	float GetHeight(bool scaled=true) const;
	int GetTextureID() const;

protected:
	Texture texture;
	Vector2 pos;
	Vector2 scale;
	Vector2 rotCenter;
	Vector2 rotCenterAdj;
	float rot;
	int interp = GL_NEAREST;

	void Initialize(const std::string& imgPath, const Vector2& _pos, const Vector2& _scale, const float& _rot);
	void Initialize(const int& imgID, const Vector2& _pos, const Vector2& _scale, const float& _rot);
	void RenderHelper(const Vector2& posOffset, const float& rotOffset) const;	
};

#endif