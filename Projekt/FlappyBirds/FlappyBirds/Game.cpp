#include "Game.h"

Game::Game() {
	bird = Bird();
	bottomObstacle = Obstacle("./resources/images/pipe.png");
	topObstacle = Obstacle("./resources/images/pipe.png");

	//set window
	window = make_shared<RenderWindow>(VideoMode(1000, 600), "FlappyBird", Style::Titlebar | Style::Close);
	window->setFramerateLimit(60);
	window->setPosition(Vector2i(0, 0));
	gravity = 0;
	frame = 0;
	space = 160.0;
	//set background
	backgroundTexture.loadFromFile("./resources/images/background.jpg");
	backgroundSprite = make_shared<Sprite>();
	backgroundSprite->setTexture(backgroundTexture);

	//set obstacles
	bottomObstacle.getSprite()->setScale(1.5f, 1.5f);
	bottomObstacle.getSprite()->setPosition(100, 200);

	topObstacle.getSprite()->setScale(1.5f, -1.5f);
	topObstacle.getSprite()->setPosition(100, 100);

};

void Game::run() {
	while (window->isOpen()) {

	}
}