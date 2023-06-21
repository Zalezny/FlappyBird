#pragma

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Background {
	Texture texture;
	shared_ptr<Sprite> sprite;
public: 
	Background();
	Texture getTexture();
	shared_ptr<Sprite> getSprite();
	void init();
};