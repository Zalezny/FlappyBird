#include "Game.h"

Game::Game() {
	window = make_shared<RenderWindow>(VideoMode(1000, 600), "FlappyBird", Style::Titlebar | Style::Close);
	window->setFramerateLimit(60);
	window->setPosition(Vector2i(0, 0));
	gravity = 0;
	frame = 0;
	space = 160.0;
	backgroundTexture.loadFromFile("./resources/images/background.jpg");
	birdTexture.loadFromFile("./resources/images/bird.png");
	pipeTexture.loadFromFile("./resources/images/pipe.png");
	
	backgroundSprite = make_shared<Sprite>();
	backgroundSprite->setTexture(backgroundTexture);
	birdSprite = make_shared<Sprite>();
	birdSprite->setTexture(birdTexture);
	pipeBottomSprite = make_shared<Sprite>();
	pipeBottomSprite->setTexture(pipeTexture);
	pipeTopSprite = make_shared<Sprite>();
	pipeTopSprite->setTexture(pipeTexture);
};

void Game::run() {
	while (window->isOpen()) {

	}
}