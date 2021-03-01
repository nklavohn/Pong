#ifndef ENGINE_TEXTURE
#define ENGINE_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL2/SOIL2.h"

#include <iostream>
#include <string>

class Texture {

public:
	Texture();
	Texture(const int& _id);
	Texture(const std::string& path);

	int GetID() const;
	int GetWidth() const;
	int GetHeight() const;

private:
	bool GetTextureParams();

	int id;
	int width;
	int height;
};

#endif