#include "Engine.h"

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = nullptr;

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::Initialize(const char* windowTitle) {
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
	glOrtho(0, width, 0, height, zNear, zFar);

	// give GL the depth range again
	glDepthRange(zNear, zFar);

	// changes the state of openGL the modelview matrix, which describes how objects are transformed (translation, rotation, etc.) in the world
	glMatrixMode(GL_MODELVIEW);

	// ----- Alpha blending ---------
	// enable blending of alpha, and define the function that does this blending. 25% alpha image on top will show 75% (1 - 0.25) of image below
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void Engine::Update() {
	// allow glfw to handle all events stacking up in the queue (moving mouse, screen around, etc.)
	glfwPollEvents();
}

void Engine::BeginRender() {
	// clear background with a color
	glClearColor(0.8, 0.8, 1, 1);

	// clear the color and the buffer by bit-wise ORing the two integers together to make a sort of mask of which things to clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender() {
	// swap buffers
	glfwSwapBuffers(window);
}