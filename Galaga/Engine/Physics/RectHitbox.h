#ifndef ENGINE_RECTHITBOX
#define ENGINE_RECTHITBOX

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Graphics/Color.h"
#include "CollisionDetector.h"

class RectHitbox : public CollisionDetector
{
public:
	RectHitbox();
	RectHitbox(float cx, float cy, float width, float height);
	RectHitbox(Vector2 _center, Vector2 _dim);
	RectHitbox(Vector4 _box);
	~RectHitbox();

	bool IsPointInside(const Vector2& p) const override;
	bool IsAnyPointInside(const std::vector<Vector2>& ps) const override;
	bool AreAllPointsInside(const std::vector<Vector2>& ps) const override;
	bool DoesLineIntersect(const Vector4& line) const override;
	bool IsCollidingWith(CollisionDetector* cDetector) const override;

	void SetHitbox(const Vector4& _box);
	void SetCenter(const Vector2& _center) override;
	void AddToCenter(const Vector2& delta) override;
	Vector2 GetCenter() const override;

	void Render(const Color& c) const override;

	Vector4 GetBox() const;
	Vector2 GetDim() const;

	std::vector<Vector4> GetSides() const;
	std::vector<Vector2> GetVertices() const;

private:
	Vector2 center;
	Vector2 dim;
	Vector4 box;  // (x,y) is bottom left and (z, w) is top right
};

#endif