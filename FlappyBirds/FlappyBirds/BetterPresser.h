#pragma once

#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

class BetterPresser {
	bool isButtonClicked;
	thread threadHandler;
	void handler();
public:
	BetterPresser();
	bool handleClickKey(Keyboard::Key keyboardBtn);
	bool handleClickMouse(Mouse::Button mouseBtn);
};