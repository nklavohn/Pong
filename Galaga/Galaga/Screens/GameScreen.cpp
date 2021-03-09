#include "GameScreen.h"

GameScreen::GameScreen(const IVector2& _dim) : Screen(_dim)
{
	color = Color(0.114, 0.114, 0.227, 1);
}

GameScreen::~GameScreen()
{

}

void GameScreen::Update()
{
	ship.Move();
	needler.Move();
}

void GameScreen::Render() const
{
	BeginRender();
	ship.Render();
	needler.Render();

	ship.DebugPhysics();
	EndRender();
}

Screen* GameScreen::Clone() const
{
	return new GameScreen(*this);
}