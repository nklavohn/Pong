#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Math/Vector.h"
#include "Galaga/Screens/GameScreen.h"

#include <iostream>
using namespace std;


int main() {
	cout << "Hello, world!" << endl;
	
	Engine engine;
	engine.SetScale(4);
	engine.Initialize("Pong");

	GameScreen screen = GameScreen(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
	engine.SetScreen(screen);

	while (true) {
		engine.Update();
		cout << "DeltaTime: " << Engine::GetDeltaTime() << endl;
		engine.Render();
	}

	return 0;
}