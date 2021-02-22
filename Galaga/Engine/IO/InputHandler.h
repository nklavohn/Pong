#ifndef ENGINE_INPUTHANDLER
#define ENGINE_INPUTHANDLER

class InputHandler {

public:
	InputHandler();
	~InputHandler();

	virtual bool Listen() = 0;
	virtual void Act() = 0;
};

#endif
