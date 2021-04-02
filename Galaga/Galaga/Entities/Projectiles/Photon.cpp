#include "Photon.h"

#include "Engine/Physics/CircHitbox.h"

Photon::Photon() : Projectile(std::unique_ptr<Hitbox>(new CircHitbox(0, 0, 5)))
{

}

Photon::Photon(const Vector2& _pos, const Vector2& _vel) : Projectile(std::unique_ptr<Hitbox>(new CircHitbox(_pos, 5)))
{
	SetPos(_pos);
	SetVel(_vel);
}

Photon::~Photon()
{

}

void Photon::Update()
{
	ApplyPhysics();
}

void Photon::Render() const
{
	//hitbox->Render(Color::BLUE);
}

void Photon::DebugPhysics() const
{
	hitbox->Render(Color::BLUE);
}