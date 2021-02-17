#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Math/Vector.h"
#include "Galaga/Screens/GameScreen.h"
#include "Galaga/Screens/TitleScreen.h"
#include "Galaga/Screens/TestScreen.h"

#include <iostream>
using namespace std;


int main() {
	cout << "Hello, world!" << endl;
	
	Engine engine;
	engine.SetScale(4);
	engine.Initialize("Galaga");

	Screen* screen = nullptr;

	int mode = -1;

	switch (mode) {
	case (0): {
		GameScreen gs = GameScreen(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
		screen = gs.Clone();
		break;
	}
	case (1): { 
		TitleScreen ts = TitleScreen(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
		screen = ts.Clone();
		break;
	}
	default: {
		TestScreen ts = TestScreen(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
		screen = ts.Clone();
		break;
	}
	}
	
	Engine::SetScreen(*screen);

	while (true) {
		engine.Update();
		cout << "DeltaTime: " << Engine::GetDeltaTime() << endl;
		engine.Render();
	}

	return 0;
}