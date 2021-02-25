#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"
#include "Engine/Math/Vector2.h"

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
float Engine::SCALE = 4;

GLFWwindow* Engine::window = nullptr;
Screen* Engine::screen = nullptr;
double Engine::deltaTime = 0;

Engine::Engine()
{
	prevTime = 0;
	maxFrameRate = 120;
}

Engine::~Engine()
{

}

bool Engine::Initialize(const char* windowTitle)
{
	// Initialize GLFW, return false if not initialized properly
	if (!glfwInit()) {
		cout << "Error initializing GLFW" << endl;
		return false;
	}

	//Create the window based on defined paraments, return false if not created correctly
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, nullptr, nullptr);
	if (window == nullptr) {
		cout << "Error creating window" << endl;
		return false;
	}

	// ---------- OpenGL Setup -------------
	// a context is set to a current window, so that anything that happens afterwards happens to that window
	glfwMakeContextCurrent(window);

	// pass in pointers to width and height, defines those variables
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	// swaps the frame buffer every frame (the are two buffers, one being shown and own being drawn, you switch between them to avoid flickering)
	// this is called double buffering
	glfwSwapInterval(1);

	// gets the video mode from our primary monitor
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	// find position of window to center it on the screen, and then set it
	int xPos = (mode->width - SCREEN_WIDTH) / 2;  // use -> instead of . because it is a pointer
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);


	// ---------- Input Event Callbacks --------
	// any time we poll events, we get new mouse data, this will call the mouse class and properly update the local variables, retrieved with getters
	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
	glfwSetKeyCallback(window, Keyboard::KeyCallback);

	// ---------- Base GL Setup --------------
	// ----- Viewport setup -------
	// has dimensions as defined above with frame buffer
	glViewport(0, 0, width, height);

	// switch to projection matrix to define the properties of the camear that views the objects in the world coordinate frame
	glMatrixMode(GL_PROJECTION);

	// start with an identity matrix
	glLoadIdentity();

	// define max and min z-value, can be used for ordering 2D images in front of each other in projection from 3D down to 2D
	int zNear = -10;
	int zFar = 10;

	// setup ortho view, width (0,0) in the bottom left corner and (width, height) in the top right corner, and define bounds for z (clipping range)
	// this is basically making the world coordinate frame
	// Here is where you can set properties like the zoom factor, aspect ratio, etc. (apparently)
	glOrtho(0, width/SCALE, 0, height/SCALE, zNear, zFar);

	// give GL the depth range again
	glDepthRange(zNear, zFar);

	// changes the state of openGL the modelview matrix, which describes how objects are transformed (translation, rotation, etc.) in the world
	glMatrixMode(GL_MODELVIEW);

	// ----- Alpha blending ---------
	// enable blending of alpha, and define the function that does this blending. 25% alpha image on top will show 75% (1 - 0.25) of image below
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// initialize prevTime
	prevTime = glfwGetTime();

	return true;
}

void Engine::Update()
{
	// calculate delta time from last frame
	double now = glfwGetTime();
	deltaTime = now - prevTime;
	prevTime = now;

	// allow glfw to handle all events stacking up in the queue (moving mouse, screen around, etc.)
	Mouse::ResetJustChanged();
	Keyboard::ResetJustChanged();
	glfwPollEvents();

	// let screen do the rest
	screen->Update();
}

void Engine::Render()
{
	screen->Render();
}

double Engine::GetDeltaTime()
{
	return deltaTime;
}

float Engine::GetScale()
{
	return SCALE;
}

void Engine::SetScale(float _scale)
{
	SCALE = _scale;
}

void Engine::SetScreen(Screen& _screen)
{
	screen = &_screen;
}

void Engine::SetFrameRate(float fRate)
{
	maxFrameRate = fRate;
}

double Engine::GetPrevTime()
{
	return prevTime;
}