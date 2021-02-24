#ifndef ENGINE_RECTCLICKLISTENER
#define ENGINE_RECTCLICKLISTENER

#include "Engine/Physics/Hitbox.h"
#include "ClickListener.h"

class RectClickListener : public ClickListener
{
public:
	RectClickListener();
	RectClickListener(int _button, Hitbox _hitbox);
	~RectClickListener();

	bool Listen() const override;
	void Act() override;
	void SetPos(const Vector2& pos) override;
	void AddToPos(const Vector2& delta) override;
	
	void Render() const;

private:
	int button;
	Hitbox hitbox;
};

#endif