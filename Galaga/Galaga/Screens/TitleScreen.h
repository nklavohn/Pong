#ifndef GALAGA_TITLESCREEN
#define GALAGA_TITLESCREEN

#include "Engine/Graphics/Sprite.h"
#include "Engine/Graphics/Screen.h"

class TitleScreen: public Screen {

public:
	void Update() override;
	void Render() override;
	Screen* Clone() override;

	TitleScreen(int w, int h);
	~TitleScreen();

private:
	Sprite title = Sprite("Galaga/Assets/title.png");

};

#endif
