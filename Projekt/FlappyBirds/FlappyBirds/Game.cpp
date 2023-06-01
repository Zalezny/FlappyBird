#include "Game.h"

Game::Game() {
	bird = Bird();
	window = make_shared<RenderWindow>(VideoMode(1000, 600), "FlappyBird", Style::Titlebar | Style::Close);
	window->setFramerateLimit(60);
	window->setPosition(Vector2i(0, 0));
	gravity = 0;
	frame = 0;
	space = 160.0;
	backgroundTexture.loadFromFile("./resources/images/background.jpg");
	pipeTexture.loadFromFile("./resources/images/pipe.png");
	
	backgroundSprite = make_shared<Sprite>();
	backgroundSprite->setTexture(backgroundTexture);
	pipeBottomSprite = make_shared<Sprite>();
	pipeBottomSprite->setTexture(pipeTexture);
	pipeTopSprite = make_shared<Sprite>();
	pipeTopSprite->setTexture(pipeTexture);
};

void Game::run() {
	while (window->isOpen()) {

	}
}