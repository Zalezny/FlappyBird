#include "Background.h"

Background::Background() {
	
}

void Background::init() {
	texture.loadFromFile("./resources/images/background.jpg");
	sprite = make_shared<Sprite>();
	sprite->setTexture(texture);
}

shared_ptr<Sprite> Background::getSprite() {
	return sprite;
}

Texture Background::getTexture() {
	return texture;
}


