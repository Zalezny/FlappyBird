#include "Obstacle.h"

Obstacle::Obstacle() {
	sprite = make_shared<Sprite>();
	sprite->setTexture(texture);
}

Obstacle::Obstacle(String texturePath) {
	sprite = make_shared<Sprite>();
	texture.loadFromFile(texturePath);
	sprite->setTexture(texture);
}

shared_ptr<Sprite> Obstacle::getSprite() {
	return sprite;
}

Texture Obstacle::getTexture() {
	return texture;
}