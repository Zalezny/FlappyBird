#include "BetterPresser.h"


BetterPresser::BetterPresser() {
	isButtonClicked = false;
}

void BetterPresser::handler() {
	this_thread::sleep_for(chrono::seconds(1));
	isButtonClicked = false;
}

bool BetterPresser::handleClickKey(Keyboard::Key key) {
	if (Keyboard::isKeyPressed(key) && !isButtonClicked) {
		isButtonClicked = true;
		threadHandler = std::thread(&BetterPresser::handler, this);
		threadHandler.detach();
		return true;
	}
	return false;
}


