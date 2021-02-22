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

	bool Listen() override;
	void Act() override;
	void SetPos(Vector2 pos) override;
	void AddToPos(Vector2 delta) override;

private:
	int button;
	Hitbox hitbox;
};

#endif