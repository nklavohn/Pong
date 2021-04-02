#include "Spaceship.h"

#include "Engine/Engine.h"
#include "Engine/Graphics/ShapeRenderer.h"
#include "Engine/Physics/CircHitbox.h"
#include "Galaga/Entities/Projectiles/Photon.h"

constexpr float exhaust_angle = 20;
constexpr float weapon_angle = 5;

Spaceship::Spaceship() : Player(std::unique_ptr<Hitbox>(new CircHitbox(Vector2::ZERO, 10))), 
	exhaust(std::make_unique<ExhaustParticle>(), 0.05F),
	weapon(new PhotoCannon(std::unique_ptr<Projectile>(new Photon()), 1))
{
	speed = 200;
	rotSpeed = 250;
	currentSprite = IVector2(1, 0);
	velDir = Vector2::JHAT;
	spriteSheet.SetRotCenter(Vector2(10.5F, 13));
}

Spaceship::~Spaceship()
{

}

void Spaceship::Update()
{
	Move();
	Shoot();
}

void Spaceship::Move()
{
	if (Keyboard::IsKeyPressed(Keyboard::W))
	{
		tState.pos += velDir * Engine::GetDeltaTime() * speed;
		hitbox->SetCenter(tState.pos);
		exhaust.Emit(tState.pos, velDir * -speed, exhaust_angle);
	}
	if (Keyboard::IsKeyPressed(Keyboard::A))
	{
		float deltaRot = rotSpeed * Engine::GetDeltaTime();
		rState.angle += deltaRot;
		velDir.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::S))
	{

	}
	if (Keyboard::IsKeyPressed(Keyboard::D))
	{
		float deltaRot = -rotSpeed * Engine::GetDeltaTime();
		rState.angle += deltaRot;
		velDir.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::E))
	{

	}
	if (Keyboard::IsKeyPressed(Keyboard::Q))
	{

	}
}

void Spaceship::Shoot()
{
	weapon->Emit(tState.pos, velDir * speed * 5, weapon_angle);
}

void Spaceship::Render() const
{
	spriteSheet.RenderRelativeTo(tState.pos, rState.angle, currentSprite);
}

Vector2 Spaceship::GetPos() const
{
	return tState.pos;
}

void Spaceship::DebugPhysics() const
{
	hitbox->Render(Color::WHITE);
	ShapeRenderer::DrawVector(Color::WHITE, tState.pos, tState.pos + velDir * 10);
}
