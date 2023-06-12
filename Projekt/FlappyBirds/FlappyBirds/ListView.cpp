#include "ListView.h"

ListView::ListView(vector<ScoreEntity>& scoresArray) : scores(scoresArray)
{
	renderWindow = RenderWindowSingleton::GetInstance()->value();
	listItemText = make_shared<Text>();
	font = make_shared<Font>();
	font->loadFromFile("./resources/fonts/flappy_bird_font.ttf");
	listItemText->setFont(*font);
	listItemText->setCharacterSize(28);
}

void ListView::show() {
	float x = renderWindow->getSize().x * 0.4;

	if (scores.empty()) {
		string emptyInfoString = "Sorry, but you have not played anything yet :-(";
		listItemText->setString(emptyInfoString);
		listItemText->setPosition(Positions::getCenter(listItemText->getGlobalBounds()));
		renderWindow->draw(*listItemText);
		return;
	}

	listItemText->setString("TOP 10");
	Vector2f posTop = Positions::getCenter(listItemText->getGlobalBounds(), 0.01);
	listItemText->setPosition(posTop);
	spaceBetweenItem += 0.05;
	renderWindow->draw(*listItemText);

	for (int i = 0; i < scores.size(); i++) {
		ostringstream textOSS;
		textOSS << i+1 << ".    " << scores[i].score << "    " << scores[i].date;
		float y = renderWindow->getSize().y * spaceBetweenItem;
		Vector2f pos = Vector2f(x, y);
		listItemText->setString(textOSS.str());
		listItemText->setPosition(pos);
		renderWindow->draw(*listItemText);
		spaceBetweenItem += 0.05;
	}
}
