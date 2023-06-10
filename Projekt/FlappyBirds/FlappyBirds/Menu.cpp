#include "Menu.h"

Menu::Menu()
{
	menuButton = TextButton();
	playButton = TextButton();
	scoreButton = TextButton();
	helperButton = TextButton();
	renderWindow = RenderWindowSingleton::GetInstance()->value();
}

void Menu::show(ScreenEnum* screen) {
	initView();
	events(screen);
}

void Menu::initView()
{
	//menuButton.show("Menu", Vector2f(renderWindow->getSize().x * 0.3, renderWindow->getSize().y * 0.7));
	playButton.show("Play", Vector2f(renderWindow->getSize().x * 0.4, renderWindow->getSize().y * 0.7));
	scoreButton.show("Score", Vector2f(renderWindow->getSize().x * 0.5, renderWindow->getSize().y * 0.5));
	helperButton.show("Help", Vector2f(renderWindow->getSize().x * 0.3, renderWindow->getSize().y * 0.5));
	renderWindow->display();
}

void Menu::events(ScreenEnum* screen) {
	if (playButton.isButtonClicked(renderWindow)) { *screen = ScreenEnum::PLAY; }
	if (scoreButton.isButtonClicked(renderWindow)) { *screen = ScreenEnum::SCORE; }
	if (helperButton.isButtonClicked(renderWindow)) { *screen = ScreenEnum::HELP; }
}