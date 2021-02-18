#ifndef ENGINE_SPRITE
#define ENGINE_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "Engine/Math/Vector.h"

#include <iostream>
#include <string>

using namespace std;

class Sprite {

public:
	Sprite();
	Sprite(string imgPath);
	Sprite(string imgPath, Vector _pos);
	Sprite(string imgPath, Vector _pos, float _scale);
	Sprite(int imgID);
	Sprite(int imgID, Vector _pos);
	Sprite(int imgID, Vector _pos, float _scale);
	~Sprite();

	void Update();
	void Render();
	void RenderRelativeTo(Vector _pos);

	void SetPos(float x, float y);
	void SetPos(Vector v);
	void SetRot(float _rot);
	void AddRot(float _rot);
	void SetScale(float xy);
	void SetScale(float x, float y);
	void SetScale(Vector v);

	void SetInterpolationFunction(int _interp);

	float GetWidth(bool scaled = true);
	float GetHeight(bool scaled = true);
	int GetTextureID();

protected:
	Texture texture;
	Vector pos;
	Vector scale;
	float rot;	
	int interp = GL_NEAREST;

	void Initialize(string imgPath, Vector _pos, Vector _scale, float _rot);
	void Initialize(int imgID, Vector _pos, Vector _scale, float _rot);
	void RenderHelper(Vector offset);
};

#endif