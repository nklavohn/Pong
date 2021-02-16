#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"

#include <iostream>
using namespace std;


int main() {
	cout << "Hello, world!" << endl;
	
	Engine engine;
	engine.SetScale(4);
	engine.Initialize("Pong");

	Sprite testSprite = Sprite("Galaga/assets/ship.png", 0, 0);
	//Sprite test2 = Sprite("Galaga/assets/ship.png", 200, 200);

	double dts[20] = { 0 };

	while (true) {
		engine.Update();
		testSprite.Update();

		if (Mouse::IsButtonPressed(Mouse::LEFT)) {
			testSprite.SetPos((float)Mouse::GetScaledMouseX(), (float)Mouse::GetScaledMouseY());
		}

		cout << "DeltaTime: " << Engine::GetDeltaTime() << endl;


		engine.BeginRender();
		// -------- all drawing below here ------------
		testSprite.Render();
		//test2.Render();



		// -------- all drawing above here ------------
		engine.EndRender();
	}

	return 0;
}