#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Obstacle {
	Texture texture;
	shared_ptr<Sprite> sprite;
public:
	Obstacle(String texturePath);
	Texture getTexture();
	shared_ptr<Sprite> getSprite();
};