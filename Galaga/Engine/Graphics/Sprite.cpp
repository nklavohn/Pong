#include "Sprite.h"


Sprite::Sprite() {
	Initialize(-1, Vector::ZERO, Vector::ONE, 0);
}

Sprite::Sprite(string imgPath) {
	Initialize(imgPath, Vector::ZERO, Vector::ONE, 0);
}

Sprite::Sprite(int imgID) {
	Initialize(imgID, Vector::ZERO, Vector::ONE, 0);
}

Sprite::Sprite(string imgPath, Vector _pos) {
	Initialize(imgPath, _pos, Vector::ONE, 0);
}

Sprite::Sprite(int imgID, Vector _pos) {
	Initialize(imgID, _pos, Vector::ONE, 0);
}

Sprite::Sprite(string imgPath, Vector _pos, float _scale) {
	Initialize(imgPath, _pos, Vector(_scale), 0);
}

Sprite::Sprite(int imgID, Vector _pos, float _scale) {
	Initialize(imgID, _pos, Vector(_scale), 0);
}

Sprite::Sprite(string imgPath, Vector _pos, Vector _scale, float _rot) {
	Initialize(imgPath, _pos, _scale, _rot);
}

Sprite::Sprite(int imgID, Vector _pos, Vector _scale, float _rot) {
	Initialize(imgID, _pos, _scale, _rot);
}

void Sprite::Initialize(string imgPath, Vector _pos, Vector _scale, float _rot) {
	texture = Texture(imgPath);
	pos = _pos.GetCopy();
	scale = _scale.GetCopy();
	rot = _rot;
	interp = GL_NEAREST;
}

void Sprite::Initialize(int imgID, Vector _pos, Vector _scale, float _rot) {
	texture = Texture(imgID);
	pos = _pos.GetCopy();
	scale = _scale.GetCopy();
	rot = _rot;
	interp = GL_NEAREST;
}

Sprite::~Sprite() {

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
	glTranslatef(pos.x, pos.y, 0);

	// then execute rotations
	// rotates around the z axis (perpendicular to screen) only, because it is a 2D game
	glRotatef(rot, 0, 0, 1);

	// then execute scales
	glScalef(scale.x, scale.y, 1);


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
	pos.x = x;
	pos.y = y;
}

void Sprite::SetPos(Vector v) {
	pos.x = v.x;
	pos.y = v.y;
}

void Sprite::SetRot(float _rot) {
	rot = _rot;
}

void Sprite::AddRot(float _rot) {
	rot += _rot;
}

void Sprite::SetScale(float xy) {
	scale.x = xy;
	scale.y = xy;
}

void Sprite::SetScale(float x, float y) {
	scale.x = x;
	scale.y = y;
}

void Sprite::SetScale(Vector v) {
	pos.x = v.x;
	pos.y = v.y;
}

void Sprite::SetInterpolationFunction(int _interp) {
	interp = _interp;
}

float Sprite::GetHeight(bool scaled) {
	if (scaled) return texture.GetHeight() * scale.y;
	return texture.GetHeight();
}

float Sprite::GetWidth(bool scaled) {
	if (scaled) return texture.GetWidth() * scale.x;
	return texture.GetWidth();
}

int Sprite::GetTextureID() {
	return texture.GetID();
}