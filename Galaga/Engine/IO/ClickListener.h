#ifndef ENGINE_CLICKLISTENER
#define ENGINE_CLICKLISTENER

#include "InputHandler.h"
#include "Engine/Math/Vector2.h"

class ClickListener : public InputHandler
{
public:
	ClickListener();
	~ClickListener();

	virtual void SetPos(const Vector2& pos) = 0;
	virtual void AddToPos(const Vector2& delta) = 0;
	virtual void Render() const = 0;

};

#endif