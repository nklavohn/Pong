#include "TitleScreen.h"
#include "GameScreen.h"
#include "Engine/Engine.h"
#include "Engine/IO/Keyboard.h"

TitleScreen::TitleScreen(int w, int h) : Screen(w, h) {
	color = Color(0.114, 0.114, 0.227, 1);
}

TitleScreen::~TitleScreen() {

}

void TitleScreen::Update() {
	if (Keyboard::IsKeyPressed(Keyboard::SPACE))
	{
		Screen* screen = nullptr;
		GameScreen s = GameScreen(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
		screen = s.Clone();
		Engine::SetScreen(*screen);
	}
	else if (Keyboard::IsKeyPressed(Keyboard::ESC))
	{
		glfwSetWindowShouldClose(Engine::window, 1);
	}
}

void TitleScreen::Render() {
	BeginRender();
	title.RenderRelativeTo(Vector2((float)Engine::SCREEN_WIDTH / Engine::SCALE / 2, (float)Engine::SCREEN_HEIGHT / Engine::SCALE / 2));
	EndRender();
}

Screen* TitleScreen::Clone() {
	return new TitleScreen(*this);
}