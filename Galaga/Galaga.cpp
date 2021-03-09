#include "Engine/Engine.h"
#include "Galaga/Screens/GameScreen.h"
#include "Galaga/Screens/TitleScreen.h"
#include "Galaga/Screens/TestScreen.h"

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void SetStartScreen(int mode);

int main()
{
	Engine engine;
	engine.SetScale(4);
	engine.Initialize("Galaga");

	int mode = 0;
	SetStartScreen(mode);

	double TARGET_FPS = 60;
	chrono::duration<double, milli> frameDur (1000 / TARGET_FPS);  // in milliseconds

	while (!glfwWindowShouldClose(Engine::window)) {
		auto start = chrono::high_resolution_clock::now();

		engine.Update();
		engine.Render();

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> sleepTime = frameDur - (end - start);
		double toSleep = sleepTime.count() / 1000;

		if (toSleep > 0)
		{
			//cout << "Elapsed: " << toSleep << endl;
			this_thread::sleep_for(sleepTime);
		}
	}

	return 0;
}

void SetStartScreen(int mode)
{
	Screen* screen = nullptr;
	switch (mode) {
	case (0): {
		screen = new GameScreen(Engine::windowPixelDim);
		break;
	}
	case (1): {
		screen = new TitleScreen(Engine::windowPixelDim);
		break;
	}
	default: {
		screen = new TestScreen(Engine::windowPixelDim);
		break;
	}
	}
	
	Engine::SetScreen(*screen);
}