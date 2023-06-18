#include "HelpScreen.h"



HelpScreen::HelpScreen()
{
	pauseText = make_shared<Text>();
	gameHelpTxt = make_shared<Text>();
	menuButton = make_shared<TextButton>();
	renderWindow = RenderWindowSingleton::GetInstance()->value();
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
}