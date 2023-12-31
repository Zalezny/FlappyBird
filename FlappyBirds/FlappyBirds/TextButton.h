#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "RenderWindowSingleton.h"
#include "BetterPresser.h"

using namespace std;
using namespace sf;

class TextButton {
	shared_ptr<Sprite> sprite;
	Texture texture;
	Font font;
	Text txt;
	BetterPresser handlePresser;
	double x, y;
	void setPosition(Vector2f pos);
	void draw();

public:
	TextButton();
	inline shared_ptr<Sprite> getSprite() { return sprite; };
	inline Text getText() { return txt; }
	void show(String textBtn, Vector2f pos, bool isSprite = true);
	bool isButtonClicked(shared_ptr<RenderWindow> window);
};

