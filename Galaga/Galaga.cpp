#include "Engine/Engine.h"
#include "Galaga/Screens/GameScreen.h"
#include "Galaga/Screens/TitleScreen.h"
#include "Galaga/Screens/TestScreen.h"

#include <iostream>
using namespace std;

void SetStartScreen(int mode);

int main() {
	Engine engine;
	engine.SetScale(4);
	engine.Initialize("Galaga");

	int mode = -1;
	SetStartScreen(mode);

	while (true) {
		engine.Update();
		cout << "DeltaTime: " << Engine::GetDeltaTime() << endl;
		engine.Render();
	}

	return 0;
}


void SetStartScreen(int mode) {
	Screen* screen = nullptr;
	switch (mode) {
	case (0): {
		GameScreen s = GameScreen(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
		screen = s.Clone();
		break;
	}
	case (1): {
		TitleScreen s = TitleScreen(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
		screen = s.Clone();
		break;
	}
	default: {
		TestScreen s = TestScreen(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
		screen = s.Clone();
		break;
	}
	}
	Engine::SetScreen(*screen);
}