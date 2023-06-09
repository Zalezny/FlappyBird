#include "TextButton.h"
TextButton::TextButton() {
	sprite = make_shared<Sprite>();
	txt = Text();
}


void TextButton::show(String textBtn, Vector2f pos) {
	texture.loadFromFile("./resources/images/buttonClick.png");
	sprite->setTexture(texture);
	sprite = make_shared<Sprite>();
	font.loadFromFile("./resources/fonts/flappy_bird_font.ttf");
	sprite->setTexture(texture);
	sprite->setScale(0.05f, 0.05f);
	txt.setFont(font);
	txt.setString(textBtn);
	txt.setCharacterSize(28);
	setPosition(pos)
}

void TextButton::setPosition(Vector2f pos) {
	sprite->setPosition(x,y);

	float pos_x = (pos.x + sprite->getGlobalBounds().width / 2.0f) -
		(txt.getGlobalBounds().width / 2);
	float pos_y = (pos.y + sprite->getGlobalBounds().height / 2.5f) -
		(txt.getGlobalBounds().height / 2);
	txt.setPosition(pos_x, pos_y);
}