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
	gameHelpTxt->setFont(*font);
	gameHelpTxt->setString("Press SPACE or LeFt Mouse Click to Fly a bird");
	gameHelpTxt->setPosition(200, 300);
	gameHelpTxt->setCharacterSize(30);
	gameHelpTxt->setOutlineThickness(3);
	pauseText->setFont(*font);
	pauseText->setString("Press P to pause");
	pauseText->setPosition(200, 200);
	pauseText->setCharacterSize(30);
	pauseText->setOutlineThickness(3);
}

void HelpScreen::show(ScreenEnum* screen)
{
	events(screen);
	createView();
}

void HelpScreen::events(ScreenEnum* screen)
{
	if (menuButton->isButtonClicked(renderWindow)) { *screen = ScreenEnum::MENU; }
}

void HelpScreen::createView()
{
	menuButton->show("Menu", Vector2f(Positions::getCenter(menuButton->getSprite()->getGlobalBounds(), 0.8F)));
	renderWindow->draw(*pauseText);
	renderWindow->draw(*gameHelpTxt);
	renderWindow->display();
}