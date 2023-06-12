#include "ScoreScreen.h"



ScoreScreen::ScoreScreen()
{
	menuButton = TextButton();
	renderWindow = RenderWindowSingleton::GetInstance()->value();

	
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
}

void ScoreScreen::createView()
{
	
	listView.show();
	renderWindow->display();
}

