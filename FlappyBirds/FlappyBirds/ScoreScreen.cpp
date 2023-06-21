#include "ScoreScreen.h"



ScoreScreen::ScoreScreen()
{
	renderWindow = RenderWindowSingleton::GetInstance()->value();
	backButton = make_shared<TextButton>();
	clearButton = make_shared<TextButton>();
	service = make_shared<FileReader>();
}

void ScoreScreen::show(ScreenEnum* screen)
{
	
	scores = service->readFile();
	listView = ListView(scores);

	createView();
	events(screen);
}

void ScoreScreen::events(ScreenEnum* screen)
{
	if (backButton->isButtonClicked(renderWindow)) { *screen = ScreenEnum::MENU; }
	if (clearButton->isButtonClicked(renderWindow)) {
		service->removeFile();
		scores.clear();
	}
}

void ScoreScreen::createView()
{
	backButton->show("MENU", Positions::getCenter(backButton->getSprite()->getGlobalBounds(), 0.95f, 0.7f));
	clearButton->show("CLEAR", Positions::getCenter(clearButton->getSprite()->getGlobalBounds(), 0.95f, 0.3f));

	listView.show();
	renderWindow->display();
}

