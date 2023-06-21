#include "Background.h"

Background::Background() {
	sprite = make_shared<Sprite>();
}

void Background::init() {
	texture.loadFromFile("./resources/images/background.jpg");
	sprite->setTexture(texture);
}

shared_ptr<Sprite> Background::getSprite() {
	return sprite;
}

Texture Background::getTexture() {
	return texture;
}


