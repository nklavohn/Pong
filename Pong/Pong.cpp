#include "Engine/Engine.h"

#include <iostream>
using namespace std;


int main() {
	cout << "Hello, world!" << endl;
	
	Engine engine;

	engine.Initialize("Pong");

	while (true) {
		engine.Update();
		engine.Render();
	}

	return 0;
}