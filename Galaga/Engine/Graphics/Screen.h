#ifndef ENGINE_SCREEN
#define ENGINE_SCREEN

#include "GLFW/glfw3.h"
#include "Color.h"

class Screen {

public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	int GetWidth();
	int GetHeight();
	void SetWidth(int w);
	void SetHeight(int h);

	Screen();
	Screen(int w, int h);
	virtual ~Screen();

protected:
	int width;
	int height;

	Color color;

	void BeginRender();
	void EndRender();
};

#endif