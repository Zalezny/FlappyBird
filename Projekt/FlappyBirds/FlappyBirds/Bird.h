#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Bird {
	int countOfObstacle = 0;
	shared_ptr<Sprite> sprite;
	Texture texture;

public:
	Bird();
	shared_ptr<Sprite> getSprite();
	Texture getTexture();

};