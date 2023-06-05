#include "Bird.h"


Bird::Bird() {
	points = 0;
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

int Bird::getX() {
	return texture.getSize().x;
}

int Bird::getY() {
	return texture.getSize().y;
}

Texture Bird::getTexture() {
	return texture;
}

void Bird::setPosition(float x, float y) {
	sprite->setPosition(x, y);
}

void Bird::setScale(float x, float y) {
	sprite->setScale(x, y);
}

void Bird::incrementPoints()
{
	++points;
}

int Bird::getPoints()
{
	return points;
}

void Bird::setPoints(int point)
{
	points = point;
}
