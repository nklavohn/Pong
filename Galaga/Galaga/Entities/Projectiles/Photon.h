#ifndef SPACEGAME_PHOTON
#define SPACEGAME_PHOTON

#include "Engine/Entities/Projectile.h"

class Photon : public Projectile
{
public:
	Photon();
	Photon(const Vector2& _pos, const Vector2& _vel);
	
	//rule of three
	~Photon();
	Photon(const Photon& other) : Photon(other.tState.pos, other.tState.vel) {}
	Photon& operator=(const Photon& other) { return *this; }

	void Update() override;
	void Render() const override;
	void DebugPhysics() const override;

	std::shared_ptr<Entity> CloneEntity() const override { return std::make_shared<Photon>(*this); }
	std::shared_ptr<Projectile> CloneProjectile() const override { return std::make_shared<Photon>(*this); }
};

#endif
