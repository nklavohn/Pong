#include "Spaceship.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Engine.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Physics/CircHitbox.h"
#include "Engine/Graphics/ShapeRenderer.h"

#include "Galaga/Entities/Particles/ExhaustParticle.h"

Spaceship::Spaceship() : Player(std::unique_ptr<Hitbox>(new CircHitbox(Vector2::ZERO, 10))),
	ConstantParticleEmitter(std::unique_ptr<Particle>(new ExhaustParticle()), 0.05F)
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
	if (Keyboard::IsKeyPressed(Keyboard::W))
	{
		hitbox->AddToCenter(velDir * Engine::GetDeltaTime() * speed);
		EmitParticles(hitbox->GetCenter(), velDir * -speed);
	}
	if (Keyboard::IsKeyPressed(Keyboard::A))
	{
		float deltaRot = rotSpeed * Engine::GetDeltaTime();
		rState.angle += deltaRot;
		vel.Rotate(deltaRot);
	}
	if (Keyboard::IsKeyPressed(Keyboard::S))
	{
		hitbox->AddToCenter(vel.Flip(false) * Engine::GetDeltaTime() * speed);
	}
	if (Keyboard::IsKeyPressed(Keyboard::D))
	{
		float deltaRot = -rotSpeed * Engine::GetDeltaTime();
		rot += deltaRot;
		vel.Rotate(deltaRot);
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
	shotCooldown -= Engine::GetDeltaTime();

	if (Mouse::IsButtonJustPressed(Mouse::LEFT) && shotCooldown <= 0)
	{
	
	}
}

void Spaceship::Render() const
{
	spriteSheet.RenderRelativeTo(hitbox->GetCenter(), rot, currentSprite);
}

bool Spaceship::IsHit()
{
	return true;
}

void Spaceship::Respawn()
{

}

void Spaceship::DebugPhysics() const
{
	if (hitbox)
	{
		hitbox->Render(Color::WHITE);
		Vector2 pos = hitbox->GetCenter();
		ShapeRenderer::DrawVector(Color::WHITE, pos, pos + vel * 10);
	}
}

Vector2 Spaceship::GetPos() const
{
	return hitbox->GetCenter();
}