#include "Obstacle.h"

Obstacle::Obstacle() {
}

void Obstacle::init() {
	sprite = make_shared<Sprite>();
	texture.loadFromFile("./resources/images/pipe.png");
	sprite->setTexture(texture);
}

shared_ptr<Sprite> Obstacle::getSprite() {
	return sprite;
}

Texture Obstacle::getTexture() {
	return texture;
}