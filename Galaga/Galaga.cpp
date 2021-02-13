#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"

#include <iostream>
using namespace std;


int main() {
	cout << "Hello, world!" << endl;
	
	Engine engine;
	engine.Initialize("Pong");

	//Sprite testSprite = Sprite();

	while (true) {
		engine.Update();
		engine.BeginRender();

		// -------- all drawing below here ------------




		// -------- all drawing above here ------------

		engine.EndRender();
	}

	return 0;
}