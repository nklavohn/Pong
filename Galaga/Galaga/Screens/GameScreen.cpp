#include "GameScreen.h"

#include "Engine/Components/Spawner.h"
#include "Engine/Systems/ParticleDecayer.h"
#include "Engine/Systems/EntityUpdater.h"
#include "Engine/Systems/EntityPhysicsDebugger.h"

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
	//Entities
	Spawner::SetDefaultSpawnQueue(registry.spawnQueue);
	ship = std::make_shared<Spaceship>();
	registry.DefinePlayer(ship);

	//Systems
	updateSystemManager.AddSystem(std::make_shared<ParticleDecayer>());
	updateSystemManager.AddSystem(std::make_shared<EntityUpdater>());

	renderSystemManager.AddSystem(std::make_shared<EntityPhysicsDebugger>());
}

void GameScreen::Update()
{
	ship->Update();

	updateSystemManager.Manage(registry);

	registry.ApplySpawnQueue();
	registry.ApplyDeleteQueue();

	Camera::Ease(ship->GetPos(), 20);
}

void GameScreen::Render() const
{
	BeginRender();
	Camera::RenderGrid(Color::DARK_GRAY, 20);

	renderSystemManager.Manage(registry);

	EndRender();
}

Screen* GameScreen::Clone() const
{
	return new GameScreen(*this);
}