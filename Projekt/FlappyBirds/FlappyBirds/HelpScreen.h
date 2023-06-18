#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <string>
#include "TextButton.h"
#include "ScreenEnum.h"
#include "Screen.h"

using namespace std;
using namespace sf;

class HelpScreen : public Screen {
	shared_ptr <Text> pauseText;
	shared_ptr <Text> gameHelpTxt;
	shared_ptr <TextButton> menuButton;
	shared_ptr<RenderWindow> renderWindow;
	void events(ScreenEnum* screen);
	void createView();
public:
	HelpScreen();
	void show(ScreenEnum* screen);
};