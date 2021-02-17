#ifndef GALAGA_TITLESCREEN
#define GALAGA_TITLESCREEN

#include "Engine/Graphics/Screen.h"

class TitleScreen: public Screen {

public:
	void Update() override;
	void Render() override;

	TitleScreen(int w, int h);
	~TitleScreen();
};

#endif
