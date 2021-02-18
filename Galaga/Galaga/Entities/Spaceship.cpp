#include "Spaceship.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Engine.h"
#include "Engine/IO/Mouse.h"

Spaceship::Spaceship()
{
	pos = Vector(30, 30);
	posMins = Vector(15, 15);
	posMaxs = Vector(15, 15);

	speed = 100;

	sprite = Sprite("Galaga/Assets/ship.png");

	numOfLives = 3;

	shotCooldownMax = 0.5;
	shotCooldown = 0;
}

Spaceship::~Spaceship()
{

}

void Spaceship::Move()
{
	Vector dir = Vector::ZERO;

	if (Keyboard::IsKeyPressed(Keyboard::W)) dir += Vector::JHAT;
	if (Keyboard::IsKeyPressed(Keyboard::A)) dir -= Vector::IHAT;
	if (Keyboard::IsKeyPressed(Keyboard::S)) dir -= Vector::JHAT;
	if (Keyboard::IsKeyPressed(Keyboard::D)) dir += Vector::IHAT;

	if (dir != Vector::ZERO)
	{
		dir = dir.Unitize();
		pos += dir * speed * Engine::GetDeltaTime();
	}

	Vector::Constrain(&pos, 
					  posMins.x, 
					  Engine::SCREEN_WIDTH / Engine::SCALE - posMaxs.x, 
					  posMaxs.y, 
					  Engine::SCREEN_HEIGHT / Engine::SCALE - posMaxs.y);
}

void Spaceship::Shoot()
{

}

void Spaceship::Render()
{
	sprite.RenderRelativeTo(pos);
}

bool Spaceship::IsHit()
{
	return true;
}

void Spaceship::Respawn()
{

}
