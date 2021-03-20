#include "HitboxHelper.h"
#include <iostream>
#include <vector>

bool HitboxHelper::RectWithRect(const RectHitbox* rect1, const RectHitbox* rect2)
{
	Vector4 box1 = rect1->GetBox();
	Vector4 box2 = rect2->GetBox();
	return (box1.x <= box2.z) && (box2.x <= box1.z) && (box1.y <= box2.w) && (box2.y <= box1.w);
}

bool HitboxHelper::RectWithCirc(const RectHitbox* rect, const CircHitbox* circ)
{
	Vector2 cirCenter = circ->GetCenter();
	float cirRadius = circ->GetRadius();

	Vector2 rectCenter = rect->GetCenter();
	float rectDiag = rect->GetDim().Len();
	float bigRad = cirRadius + rectDiag / 2;

	/*if (Vector2::Dist2Between(rectCenter, cirCenter) > bigRad * bigRad)
		return false;*/

	std::vector<Vector4> sides = rect->GetSides();

	return (rect->IsPointInside(cirCenter)  ||
		circ->DoesLineIntersect(sides[0]) ||
		circ->DoesLineIntersect(sides[1]) ||
		circ->DoesLineIntersect(sides[2]) ||
		circ->DoesLineIntersect(sides[3]) ||
		circ->IsAnyPointInside(rect->GetVertices())
		);
}

bool HitboxHelper::RectWithPoint(const RectHitbox* rect, const PointHitbox* point)
{
	Vector2 pointCenter = point->GetCenter();
	return rect->IsPointInside(pointCenter);
}

bool HitboxHelper::CircWithCirc(const CircHitbox* circ1, const CircHitbox* circ2)
{
	float bigRad = circ1->GetRadius() + circ2->GetRadius();
	Vector2 cToC = circ1->GetCenter() - circ2->GetCenter();
	return cToC.Len2() <= bigRad * bigRad;
}

bool HitboxHelper::CircWithPoint(const CircHitbox* circ, const PointHitbox* point)
{
	Vector2 pointCenter = point->GetCenter();
	return circ->IsPointInside(pointCenter);
}

bool HitboxHelper::PointWithPoint(const PointHitbox* point1, const PointHitbox* point2)
{
	Vector2 point2Center = point2->GetCenter();
	return point1->IsPointInside(point2Center);
}
