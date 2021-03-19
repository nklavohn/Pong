#ifndef SPACEGAME_NEEDLER
#define SPACEGAME_NEEDLER

#include "Engine/Entities/Entity.h"
#include "Engine/Math/Vector2.h"

class Needler : public Entity
{
public:
	Needler();
	Needler(const Vector2& _pos);
	~Needler();

	void Move() override;
	void Render() const override;
	void DebugPhysics() const override;

};

#endif