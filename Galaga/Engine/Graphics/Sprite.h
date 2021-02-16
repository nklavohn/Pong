#ifndef SPRITE
#define SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"

#include <iostream>
#include <string>

using namespace std;

class Sprite {

public:
	Sprite();
	Sprite(string imgPath);
	Sprite(int imgID);
	Sprite(string imgPath, float _xPos, float _yPos);
	Sprite(string imgPath, float _xPos, float _yPos, float scale);
	Sprite(string imgPath, float _xPos, float _yPos, float _rot, float _xScale, float _yScale);

	void Update();
	void Render();

	void SetPos(float x, float y);
	void SetRot(float _rot);
	void AddRot(float _rot);
	void SetScale(float xy);
	void SetScale(float x, float y);

	void SetInterpolationFunction(int _interp);

private:
	Texture texture;
	float xPos;  // center of image
	float yPos;  // center of image
	float rot;  // measured in degrees counterclockwise
	float xScale;
	float yScale;
	
	int interp;
};

#endif