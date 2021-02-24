#ifndef ENGINE_SPRITE
#define ENGINE_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "Engine/Math/Vector2.h"

#include <iostream>
#include <string>

class Sprite {

public:
	Sprite();
	Sprite(std::string imgPath);
	Sprite(std::string imgPath, Vector2 _pos);
	Sprite(std::string imgPath, Vector2 _pos, float _scale);
	Sprite(int imgID);
	Sprite(int imgID, Vector2 _pos);
	Sprite(int imgID, Vector2 _pos, float _scale);
	~Sprite();

	void Update();
	void Render();
	void RenderRelativeTo(Vector2 _pos);

	void SetPos(float x, float y);
	void SetPos(Vector2 v);
	void SetRot(float _rot);
	void AddRot(float _rot);
	void SetScale(float xy);
	void SetScale(float x, float y);
	void SetScale(Vector2 v);

	void SetInterpolationFunction(int _interp);

	float GetWidth(bool scaled = true);
	float GetHeight(bool scaled = true);
	int GetTextureID();

protected:
	Texture texture;
	Vector2 pos;
	Vector2 scale;
	float rot;	
	int interp = GL_NEAREST;

	void Initialize(std::string imgPath, Vector2 _pos, Vector2 _scale, float _rot);
	void Initialize(int imgID, Vector2 _pos, Vector2 _scale, float _rot);
	void RenderHelper(Vector2 offset);
};

#endif