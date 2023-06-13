#include "ScoreScreen.h"



ScoreScreen::ScoreScreen()
{
	renderWindow = RenderWindowSingleton::GetInstance()->value();
	menuButton = make_shared<TextButton>();
}

void ScoreScreen::show(ScreenEnum* screen)
{
	FileReader service = FileReader();
	scores = service.readFile();
	listView = ListView(scores);

	createView();
	events(screen);
}

void ScoreScreen::events(ScreenEnum* screen)
{
	if (menuButton->isButtonClicked(renderWindow)) { *screen = ScreenEnum::MENU; }
}

void ScoreScreen::createView()
{
	menuButton->show("MENU", Positions::getCenter(menuButton->getSprite()->getGlobalBounds(), 0.95f));

	listView.show();
	renderWindow->display();
}

