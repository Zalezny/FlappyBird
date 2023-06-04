#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Obstacle {
	Texture texture;
	shared_ptr<Sprite> sprite;
public:
	Obstacle();
	Texture getTexture();
	shared_ptr<Sprite> getSprite();
	void init();
	void setPosition(float x, float y);
	void setScale(float x, float y);
};