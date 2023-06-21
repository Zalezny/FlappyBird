#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextButton.h"
#include "RenderWindowSingleton.h"
#include "ScreenEnum.h"
#include "Screen.h"
#include "Positions.h"

using namespace std;
using namespace sf;

class MenuScreen : public Screen {
	shared_ptr<RenderWindow> renderWindow;
	TextButton menuButton;
	TextButton playButton;
	TextButton scoreButton;
	TextButton helperButton;
	Text flappyBird;
	Font font;
	void events(ScreenEnum* screen);
	void createView();
public:
	MenuScreen();
	void show(ScreenEnum* screen);
	

};