#include "Sprite.h"

Sprite::Sprite() {
	texture = Texture();
	xPos = 0;
	yPos = 0;
	rot = 0;
	xScale = 1;
	yScale = 1;
	interp = GL_NEAREST;
}

Sprite::Sprite(string imgPath) {
	texture = Texture(imgPath);
	xPos = 0;
	yPos = 0;
	rot = 0;
	xScale = 1;
	yScale = 1;
	interp = GL_NEAREST;
}

Sprite::Sprite(int imgID) {
	texture = Texture(imgID);
	xPos = 0;
	yPos = 0;
	rot = 0;
	xScale = 1;
	yScale = 1;
	interp = GL_NEAREST;
}

Sprite::Sprite(string imgPath, float _xPos, float _yPos) {
	texture = Texture(imgPath);
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	xScale = 1;
	yScale = 1;
	interp = GL_NEAREST;
}

Sprite::Sprite(string imgPath, float _xPos, float _yPos, float scale) {
	texture = Texture(imgPath);
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	xScale = scale;
	yScale = scale;
	interp = GL_NEAREST;
}

Sprite::Sprite(string imgPath, float _xPos, float _yPos, float _rot, float _xScale, float _yScale) {
	texture = Texture(imgPath);
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	xScale = _xScale;
	yScale = -yScale;
	interp = GL_NEAREST;
}

void Sprite::Update() {

}

void Sprite::Render() {
	// ------------ Setup -------------
	// because gl is a state machine, we do not know what state it may be when this code is run, so we need to do a few things first
	// enable the texture_2D
	glEnable(GL_TEXTURE_2D);

	// bind the texture's id to GL_TEXTURE_2D
	glBindTexture(GL_TEXTURE_2D, texture.GetID());

	// set the type of interpolation/filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, interp);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, interp);

	// start fresh with the identity matrix (no transformations)
	glLoadIdentity();

	// first execute locations
	glTranslatef(xPos, yPos, 0);

	// then execute rotations
	// rotates around the z axis (perpendicular to screen) only, because it is a 2D game
	glRotatef(rot, 0, 0, 1);

	// then execute scales
	glScalef(xScale, yScale, 1);


	// --------- Actual Rendering ----------
	// we don't know what the color is currently set to, so set it to white with full alpha
	glColor4f(1, 1, 1, 1);

	// begin rendering
	glBegin(GL_QUADS);

	// this takes the bottom left coordinate of the image, (0,0) and draws it at (xPos, yPos)
	// because we translated already above, xPos and yPos is now at (0, 0)
	glTexCoord2f(0, 0);		glVertex2f(0, 0);

	// around the image counter clockwise (this matters)
	glTexCoord2f(1, 0);		glVertex2f(texture.GetWidth(), 0);
	glTexCoord2f(1, 1);		glVertex2f(texture.GetWidth(), texture.GetHeight());
	glTexCoord2f(0, 1);		glVertex2f(0, texture.GetHeight());

	// ends the drawing. its a state machine, so you need to end what you are doing
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Sprite::SetPos(float x, float y) {
	xPos = x;
	yPos = y;
}

void Sprite::SetRot(float _rot) {
	rot = _rot;
}

void Sprite::AddRot(float _rot) {
	rot += _rot;
}

void Sprite::SetScale(float xy) {
	xScale = xy;
	yScale = xy;
}

void Sprite::SetScale(float x, float y) {
	xScale = x;
	yScale = y;
}

void Sprite::SetInterpolationFunction(int _interp) {
	interp = _interp;
}