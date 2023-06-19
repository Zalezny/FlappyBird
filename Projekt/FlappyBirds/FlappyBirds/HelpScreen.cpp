#include "HelpScreen.h"



HelpScreen::HelpScreen()
{
	pauseText = make_shared<Text>();
	gameHelpTxt = make_shared<Text>();
	menuButton = make_shared<TextButton>();
	renderWindow = RenderWindowSingleton::GetInstance()->value();

	//font
	font = make_shared<Font>();
	font->loadFromFile("./resources/fonts/flappy_bird_font.ttf");
	pauseText->setFont(*font);
	pauseText->setString("Press SPACE or Left Mouse Click to fly a bird");
	pauseText->setPosition(200, 300);
	pauseText->setCharacterSize(50);
	pauseText->setOutlineThickness(3);
}

void HelpScreen::show(ScreenEnum* screen)
{
	events(screen);
	createView();
}

void HelpScreen::events(ScreenEnum* screen)
{

}

void HelpScreen::createView()
{
	renderWindow->draw(*pauseText);
	renderWindow->display();
}