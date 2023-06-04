#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Bird {
	int countOfObstacles;
	shared_ptr<Sprite> sprite;
	Texture texture;

public:
	Bird();
	void init();
	shared_ptr<Sprite> getSprite();
	Texture getTexture();
	void setPosition(float x, float y);
	void setScale(float x, float y);

};