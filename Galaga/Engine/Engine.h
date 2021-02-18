#ifndef ENGINE
#define ENGINE

#include "GLFW/glfw3.h"
#include "Engine/Graphics/Screen.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>
using namespace std;

class Engine {

public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float SCALE;

	static GLFWwindow* window;
	static Screen* screen;

	static double GetDeltaTime();
	static float GetScale();
	static void SetScale(float scale);
	static void SetScreen(Screen& _screen);

	Engine();
	~Engine();

	bool Initialize(const char* windowTitle);
	
	void Update();
	void Render();
	void SetFrameRate(float fRate);

private:
	static double deltaTime;

	double prevTime;
	float maxFrameRate;
};

#endif