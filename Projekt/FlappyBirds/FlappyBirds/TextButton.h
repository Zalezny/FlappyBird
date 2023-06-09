#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class TextButton {
	shared_ptr<Sprite> sprite;
	Texture texture;
	Font font;
	Text txt;
	double x, y;
	void setPosition(Vector2f pos);

public:
	TextButton();
	inline shared_ptr<Sprite> getSprite() {
		return sprite;
	};
	inline Text getText() {
		return txt;
	}
	void show(String textBtn, Vector2f pos);
};

