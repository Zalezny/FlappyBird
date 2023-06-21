#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
	menuButton = TextButton();
	playButton = TextButton();
	scoreButton = TextButton();
	helperButton = TextButton();
	renderWindow = RenderWindowSingleton::GetInstance()->value();

	//font 
	font.loadFromFile("./resources/fonts/flappy_bird_font.ttf");
	//flappy text
	flappyBird.setFont(font);
	flappyBird.setString("FlappyBird");
	flappyBird.setPosition(Vector2f(250, 100));
	flappyBird.setCharacterSize(100);
	flappyBird.setOutlineThickness(5);
}

void MenuScreen::show(ScreenEnum* screen) {
	createView();
	events(screen);
}

void MenuScreen::createView()
{
	playButton.show("Play", Vector2f(renderWindow->getSize().x * 0.4, renderWindow->getSize().y * 0.7));
	scoreButton.show("Score", Vector2f(renderWindow->getSize().x * 0.5, renderWindow->getSize().y * 0.5));
	helperButton.show("Help", Vector2f(renderWindow->getSize().x * 0.3, renderWindow->getSize().y * 0.5));
	renderWindow->draw(flappyBird);
	renderWindow->display();
}

void MenuScreen::events(ScreenEnum* screen) {
	if (playButton.isButtonClicked(renderWindow)) { *screen = ScreenEnum::PLAY; }
	if (scoreButton.isButtonClicked(renderWindow)) { *screen = ScreenEnum::SCORE; }
	if (helperButton.isButtonClicked(renderWindow)) { *screen = ScreenEnum::HELP; }
}