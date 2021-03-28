#ifndef ENGINE_PHYSICALSTATE
#define ENGINE_PHYSICALSTATE

#include "Engine/Math/Vector2.h"

#include <queue>

class TranslationalState2
{
public:
	TranslationalState2();
	TranslationalState2(const float& _mass, const bool _hasGravity, const float& _dragCoeff, const bool _hasDrag);
	TranslationalState2(const Vector2& _pos, const Vector2& _vel, const float& _mass, 
					    const bool _hasGravity, const float& _dragCoeff, const bool _hasDrag);
	~TranslationalState2();

	float mass;
	float dragCoefficient;

	bool hasGravity;
	bool hasDrag;

	Vector2 prevPos;
	Vector2 prevVel;
	Vector2 pos;
	Vector2 vel;
	Vector2 accel;
	std::queue<Vector2> forces;

	void AddForce(const Vector2& force);
	void Move();

	/*bool HasGravity() const;
	bool HasDrag() const;

	void SetGravityTo(const bool state);
	void SetDragTo(const bool state);
	void SetDragCoefficient(const float& dragCoeff);

	Vector2 Pos() const;
	Vector2 Vel() const;
	Vector2 Accel() const;
	Vector2 PrevPos() const;
	Vector2 PrevVel() const;

	void SetPos(const Vector2& _pos);
	void SetVel(const Vector2& _vel);*/

private:
	void Initialize(const Vector2& _pos, const Vector2& _vel, const float& _mass,
					const bool _hasGravity, const float& _dragCoeff, const bool _hasDrag);
};


#endif
