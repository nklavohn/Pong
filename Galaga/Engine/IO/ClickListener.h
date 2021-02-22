#ifndef ENGINE_CLICKLISTENER
#define ENGINE_CLICKLISTENER

#include "InputHandler.h"

class ClickListener : public InputHandler
{
public:
	ClickListener();
	~ClickListener();

	virtual void SetPos(Vector2 pos) = 0;
	virtual void AddToPos(Vector2 delta) = 0;

};

#endif