#include "Bird.h"


Bird::Bird() {
	countOfObstacles = 0;
};

void Bird::init() {
	texture.loadFromFile("./resources/images/birds.png");
	sprite = make_shared<Sprite>();
	//basic config
	sprite->setTexture(texture);
	sprite->setPosition(
		500.f - texture.getSize().x / 2.f,
		500.f - texture.getSize().y / 2.f
	);
	sprite->setScale(2.f, 2.f);
	sprite->setTextureRect(IntRect(0, 0, 34, 24));
}

shared_ptr<Sprite> Bird::getSprite() {
	return sprite;
}

Texture Bird::getTexture() {
	return texture;
}

void Bird::setPosition(float x, float y) {
	sprite->setPosition(x, y);
}