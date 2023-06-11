#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextButton.h"
#include "RenderWindowSingleton.h"
#include "ScreenEnum.h"

using namespace std;
using namespace sf;

class MenuScreen {
	shared_ptr<RenderWindow> renderWindow;
	TextButton menuButton;
	TextButton playButton;
	TextButton scoreButton;
	TextButton helperButton;
	void events(ScreenEnum* screen);
	void initView();
public:
	MenuScreen();
	void show(ScreenEnum* screen);
	

};