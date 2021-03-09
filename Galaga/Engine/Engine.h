#ifndef ENGINE
#define ENGINE

#include "GLFW/glfw3.h"
#include "Engine/Graphics/Screen.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>
using namespace std;

class Engine {

public:
	static IVector2 windowPixelDim;

	static GLFWwindow* window;
	static Screen* screen;

	static double GetDeltaTime();
	static float GetScale();
	static void SetScale(const float& scale);
	static void SetScreen(Screen& _screen);

	Engine();
	~Engine();

	bool Initialize(const char* windowTitle);
	
	void Update();
	void Render() const;
	void SetFrameRate(const float& fRate);
	double GetPrevTime() const;

private:
	static double deltaTime;
	static float displayScaling;

	double prevTime;
	float maxFrameRate;
};

#endif