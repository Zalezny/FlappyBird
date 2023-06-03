#include "Game.h"

Game::Game() {
	bird = Bird();
	bottomObstacle = Obstacle();
	topObstacle = Obstacle();
	background = Background();

	background.init();
	topObstacle.init();
	bottomObstacle.init();
	bird.init();

	//set window
	window = make_shared<RenderWindow>(VideoMode(1000, 600), "FlappyBird", Style::Titlebar | Style::Close);
	window->setFramerateLimit(60);
	window->setPosition(Vector2i(0, 0));
	gravity = 0;
	frame = 0;
	space = 160.0;
	//set background
	

	//set obstacles
	bottomObstacle.getSprite()->setScale(1.5f, 1.5f);
	bottomObstacle.getSprite()->setPosition(100, 200);

	topObstacle.getSprite()->setScale(1.5f, -1.5f);
	topObstacle.getSprite()->setPosition(100, 100);

};

void Game::run() {
	while (window->isOpen()) {
		events();
		draw();
	}
}

void Game::events() {
	auto event = std::make_shared<sf::Event>();
	while (window->pollEvent(*event)) {
		if (event->type == Event::Closed) {
			window->close();
		}
	}
}

void Game::draw() {
	window->clear(sf::Color::Black);
	window->draw(*background.getSprite());
	window->draw(*bird.getSprite());
	window->draw(*bottomObstacle.getSprite());
	window->draw(*topObstacle.getSprite());
	window->display();
}