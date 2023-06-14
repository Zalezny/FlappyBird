#include "TextButton.h"
TextButton::TextButton() {
	sprite = make_shared<Sprite>();
	txt = Text();
	handlePresser = BetterPresser();
}


void TextButton::show(String textBtn, Vector2f pos, bool isSprite) {
	if (isSprite) {
		texture.loadFromFile("./resources/images/buttonClick.png");
		sprite->setTexture(texture);
		sprite->setScale(0.05f, 0.05f);
	}
	
	font.loadFromFile("./resources/fonts/flappy_bird_font.ttf");
	txt.setFont(font);
	txt.setString(textBtn);
	txt.setCharacterSize(28);
	setPosition(pos);
	draw();
}

void TextButton::setPosition(Vector2f pos) {
	sprite->setPosition(pos.x,pos.y);

	float pos_x = (pos.x + sprite->getGlobalBounds().width / 2.0f) -
		(txt.getGlobalBounds().width / 2);
	float pos_y = (pos.y + sprite->getGlobalBounds().height / 2.5f) -
		(txt.getGlobalBounds().height / 2);
	txt.setPosition(pos_x, pos_y);
}

void TextButton::draw() {
	shared_ptr<RenderWindow> renderWindow = RenderWindowSingleton::GetInstance()->value();
	renderWindow->draw(*sprite);
	renderWindow->draw(txt);
}

bool TextButton::isButtonClicked(shared_ptr<RenderWindow> window)
{
	if (handlePresser.handleClickMouse(Mouse::Left))
	{
		sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
		sf::FloatRect boundsSprite = sprite->getGlobalBounds();
		sf::FloatRect boundsTxt = txt.getGlobalBounds();
		if (boundsSprite.contains(mouse) || boundsTxt.contains(mouse))
		{
			return true;
		}
	}
	return false;
}
