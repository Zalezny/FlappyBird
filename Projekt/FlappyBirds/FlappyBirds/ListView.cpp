#include "ListView.h"

ListView::ListView(vector<ScoreEntity>& scoresArray) : scores(scoresArray)
{
	renderWindow = RenderWindowSingleton::GetInstance()->value();
	listItemText = make_shared<Text>();
	font = make_shared<Font>();
	font->loadFromFile("./resources/fonts/flappy_bird_font.ttf");
	listItemText->setFont(*font);
	listItemText->setCharacterSize(18);
}

void ListView::show() {

	if (scores.empty()) {
		//TODO: Poka¿ tekst ¿e jest pusta
		return;
	}

	for (int i = 0; i < scores.size(); i++) {
		string text = i + ". " + scores[i].score + scores[i].date;
		float x = renderWindow->getSize().x * 0.2;
		float y = renderWindow->getSize().y * spaceBetweenItem;
		Vector2f pos = Vector2f(x, y);
		listItemText->setString(text);
		listItemText->setPosition(pos);
		renderWindow->draw(*listItemText);
		spaceBetweenItem += listItemText->getGlobalBounds().height;
	}
}
