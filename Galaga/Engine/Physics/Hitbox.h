#ifndef ENGINE_HITBOX
#define ENGINE_HITBOX

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Graphics/Color.h"
#include "CollisionDetector.h"
#include "Hitcircle.h"

class Hitbox : public CollisionDetector
{
public:
	Hitbox();
	Hitbox(float cx, float cy, float width, float height);
	Hitbox(Vector2 _center, Vector2 _dim);
	Hitbox(Vector4 _box);
	~Hitbox();

	bool IsPointInside(const Vector2& p) const;
	bool AreAllPointsInside(const vector<Vector2>& ps) const;
	bool DoesLineIntersect(const Vector4& line) const;
	bool IsCollidingWith(CollisionDetector* cDetector) const;

	void SetHitbox(const Vector4& _box);
	void SetCenter(const Vector2& _center);
	void AddToCenter(const Vector2& delta);

	void Render(const Color& c) const;

	Vector2 GetCenter() const;
	Vector4 GetBox() const;
	Vector2 GetDim() const;

	vector<Vector4> GetSides() const;
	vector<Vector2> GetVertices() const;

private:
	Vector2 center;
	Vector2 dim;
	Vector4 box;  // (x,y) is bottom left and (z, w) is top right
};

#endif