#ifndef SPACEGAME_SMALLSHOT
#define SPACEGAME_SMALLSHOT

#include "Engine/Entities/Entity.h"
#include "Engine/Physics/PointHitbox.h"

class SmallShot : public Entity
{
public:
	SmallShot();
	SmallShot(Vector2 _pos, Vector2 _vel);
	~SmallShot();

	void Move() override;
	void Render() const override;
	void DebugPhysics() const override;

private:
	
};

#endif