#include "GameScreen.h"

GameScreen::GameScreen(const IVector2& _dim) : Screen(_dim)
{
	color = Color(0.114, 0.114, 0.227, 1);
}

GameScreen::~GameScreen()
{

}

void GameScreen::Setup()
{
	Entity::SetDefaultSpawnQueue(registry.spawnQueue)
}

void GameScreen::Update()
{
	ship.Move();
	Camera::Ease(ship.GetPos(), 20);
}

void GameScreen::Render() const
{
	BeginRender();
	Camera::RenderGrid(Color::DARK_GRAY, 20);
	//ship.Render();

	ship.DebugPhysics();
	EndRender();
}

Screen* GameScreen::Clone() const
{
	return new GameScreen(*this);
}