#include "GameScreen.h"

#include "Engine/Components/Spawner.h"

GameScreen::GameScreen(const IVector2& _dim) : Screen(_dim)
{
	color = Color(0.114, 0.114, 0.227, 1);
	Setup();
}

GameScreen::~GameScreen()
{

}

void GameScreen::Setup()
{
	Spawner::SetDefaultSpawnQueue(registry.spawnQueue);
	ship = std::make_shared<Spaceship>();
	registry.DefinePlayer(ship);

}

void GameScreen::Update()
{
	ship->Move();

	registry.ApplySpawnQueue();
	registry.ApplyDeleteQueue();


	Camera::Ease(ship->GetPos(), 20);
}

void GameScreen::Render() const
{
	BeginRender();
	Camera::RenderGrid(Color::DARK_GRAY, 20);
	//ship->Render();

	ship->DebugPhysics();
	registry.particles.DebugPhysics();
	EndRender();
}

Screen* GameScreen::Clone() const
{
	return new GameScreen(*this);
}