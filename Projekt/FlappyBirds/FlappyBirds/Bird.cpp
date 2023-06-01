#include "Bird.h"


Bird::Bird() {
	texture.loadFromFile("./resources/images/bird.png");
	sprite = make_shared<Sprite>();
	sprite->setTexture(texture);
};

shared_ptr<Sprite> Bird::getSprite() {
	return sprite;
}

Texture Bird::getTexture() {
	return texture;
}