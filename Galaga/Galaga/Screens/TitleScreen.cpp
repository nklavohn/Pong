#include "TitleScreen.h"

TitleScreen::TitleScreen(int w, int h) : Screen(w, h) {
	color = Color::BLUE;
}

TitleScreen::~TitleScreen() {

}

void TitleScreen::Update() {

}

void TitleScreen::Render() {
	BeginRender();
	EndRender();
}

Screen* TitleScreen::Clone() {
	return new TitleScreen(*this);
}