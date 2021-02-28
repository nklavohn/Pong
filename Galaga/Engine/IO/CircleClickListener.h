#ifndef ENGINE_CIRCLECLICKLISTENER
#define ENGINE_CIRCLECLICKLISTENER

#include "ClickListener.h"
#include "Engine/Physics/CircHitbox.h"
#include "Engine/Math/Vector2.h";

class CircleClickListener : public ClickListener
{
public:
	CircleClickListener();
	CircleClickListener(int _button, CircHitbox _hitcircle);
	~CircleClickListener();

	bool Listen() const override;
	void Act() override;
	void SetPos(const Vector2& pos) override;
	void AddToPos(const Vector2& delta) override;

	void Render() const;

private:
	int button;
	CircHitbox hitcircle;
};

#endif