#ifndef ENGINE
#define ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>
using namespace std;

class Engine {

public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float SCALE;

	static double GetDeltaTime();
	static float GetScale();
	static void SetScale(float scale);

	Engine();
	~Engine();

	bool Initialize(const char* windowTitle);

	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
	static double deltaTime;

	double prevTime;
};

#endif