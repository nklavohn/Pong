#ifndef ENGINE_COLLISIONDETECTORHELPER
#define ENGINE_COLLISIONDETECTORHELPER

#include "RectHitbox.h"
#include "CircHitbox.h"
#include "PointHitbox.h"

class CollisionDetectorHelper
{

public:
	static bool RectWithRect(const RectHitbox* rect1, const RectHitbox* rect2);
	static bool RectWithCirc(const RectHitbox* rect, const CircHitbox* circ);
	static bool RectWithPoint(const RectHitbox* rect, const PointHitbox* point);

	static bool CircWithCirc(const CircHitbox* circ1, const CircHitbox* circ2);
	static bool CircWithPoint(const CircHitbox* circ1, const PointHitbox* point);

	static bool PointWithPoint(const PointHitbox* point1, const PointHitbox* point2);

};

#endif