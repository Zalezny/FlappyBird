#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextButton.h"

using namespace std;
using namespace sf;

class Menu {
	TextButton menuButton;
	TextButton playButton;
	TextButton scoreButton;
	TextButton helperButton;
public:
	Menu();
	void show();
	void draw();
	void events();

};