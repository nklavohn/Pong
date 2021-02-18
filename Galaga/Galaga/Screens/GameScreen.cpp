#include "GameScreen.h"

GameScreen::GameScreen(int w, int h) : Screen(w, h) {
	color = Color(0.114, 0.114, 0.227, 1);
}

GameScreen::~GameScreen() {

}

void GameScreen::Update() {
	ship.Move();
}

void GameScreen::Render() {
	BeginRender();
	ship.Render();
	EndRender();
}

Screen* GameScreen::Clone() {
	return new GameScreen(*this);
}