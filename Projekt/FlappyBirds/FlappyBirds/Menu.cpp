#include "Menu.h"

Menu::Menu()
{
	menuButton = TextButton();
	playButton = TextButton();
	scoreButton = TextButton();
	helperButton = TextButton();
}

void Menu::show()
{
	menuButton.show("Menu", Vector2f(200, 200));
	playButton.show("Play", Vector2f(200, 200));
	scoreButton.show("Score", Vector2f(200, 200));
	helperButton.show("Help", Vector2f(200, 200));

}

void Menu::draw()
{
}

void Menu::events()
{
}
