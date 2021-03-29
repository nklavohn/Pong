#ifndef ENGINE_ROTATIONALSTATE
#define ENGINE_ROTATIONALSTATE

#include "Engine/Math/Vector2.h"

#include <queue>

class RotationalState
{
public:
	RotationalState();
	RotationalState(const float& _rotInertia, const bool _hasDrag, const float& _dragCoeff);
	RotationalState(const float& _angle, const float& _vel, const float& _rotInertia, 
					const bool _hasDrag, const float& _dragCoeff);
	~RotationalState();

	float prevAngle;
	float prevVel;
	float angle;
	float vel;
	float rotInertia;

	bool hasDrag;
	float dragCoefficient;

	std::queue<float> moments;

	void AddMoment(const float& moment);
	void Move();

	/*bool HasDrag() const;

	void SetDragTo(const bool state);
	void SetDragCoefficient(const float& dragCoeff);*/

private:
	void Initialize(const float& _angle, const float& _vel, const float& _rotInertia,
					const bool _hasDrag, const float& _dragCoeff);
};

#endif
