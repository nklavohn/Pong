#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"

#include <iostream>
using namespace std;


int main() {
	cout << "Hello, world!" << endl;
	
	Engine engine;
	engine.Initialize("Pong");

	Sprite testSprite = Sprite("Galaga/assets/ship.png", 100, 100, 10);
	Sprite test2 = Sprite("Galaga/assets/ship.png", 200, 200);

	while (true) {
		engine.Update();
		testSprite.Update();

		if (Mouse::isButtonPressed(Mouse::LEFT)) {
			testSprite.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());
		}

		engine.BeginRender();

		// -------- all drawing below here ------------
		testSprite.Render();
		test2.Render();



		// -------- all drawing above here ------------

		engine.EndRender();
	}

	return 0;
}