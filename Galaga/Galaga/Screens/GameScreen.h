#ifndef SPACEGAME_GAMESCREEN
#define SPACEGAME_GAMESCREEN

#include "Engine/Graphics/Screen.h"
#include "Galaga/Entities/Spaceship.h"
#include "Engine/Entities/EntityRegistry.h"

class GameScreen: public Screen
{

public: 
	void Update() override;
	void Render() const override;
	Screen* Clone() const override;

	GameScreen(const IVector2& _dim);
	~GameScreen();

private:
	EntityRegistry registry = EntityRegistry();
	std::shared_ptr<Spaceship> ship = nullptr;

	void Setup();
};

#endif