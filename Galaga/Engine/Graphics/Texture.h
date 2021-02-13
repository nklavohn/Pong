#ifndef TEXTURE
#define TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL2/SOIL2.h"

#include <iostream>
#include <string>
using namespace std;

class Texture {

public:
	Texture();
	Texture(int _id);
	Texture(string path);

	int GetID();
	int GetWidth();
	int GetHeight();

private:
	bool GetTextureParams();

	int id;
	int width;
	int height;
};

#endif