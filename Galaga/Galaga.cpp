#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"

#include <iostream>
using namespace std;


int main() {
	cout << "Hello, world!" << endl;
	
	Engine engine;
	engine.Initialize("Pong");

	Sprite testSprite = Sprite("Galaga/assets/ship.png", 100, 100);

	while (true) {
		engine.Update();
		testSprite.Update();

		if (Mouse::isButtonJustReleased(Mouse::MIDDLE)) {
			testSprite.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());
		}

		engine.BeginRender();

		// -------- all drawing below here ------------
		testSprite.Render();



		// -------- all drawing above here ------------

		engine.EndRender();
	}

	return 0;
}