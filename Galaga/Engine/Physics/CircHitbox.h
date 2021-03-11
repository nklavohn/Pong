#ifndef ENGINE_CIRCHITBOX
#define ENGINE_CIRCHITBOX

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector4.h"
#include "Engine/Graphics/Color.h"
#include "CollisionDetector.h"

class CircHitbox : public Hitbox
{
public:
	CircHitbox();
	CircHitbox(float cx, float cy, float _r);
	CircHitbox(Vector2 _center, float _r);
	~CircHitbox();

	bool IsPointInside(const Vector2& p) const override;
	bool IsAnyPointInside(const std::vector<Vector2>& ps) const override;
	bool AreAllPointsInside(const std::vector<Vector2>& ps) const override;
	bool DoesLineIntersect(const Vector4& line) const override;
	bool IsCollidingWith(Hitbox* cDetector) const override;

	void SetRadius(float _r);
	void SetCenter(const Vector2& _center) override;
	void AddToCenter(const Vector2& delta) override;

	void Render(const Color& c) const override;

	Vector2 GetCenter() const;
	float GetRadius() const;

private:
	Vector2 center;
	float r;

	void Initialize(float cx, float cy, float _r);
};

#endif