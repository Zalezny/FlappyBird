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
	windowConfig = WindowConfig();
	renderWindow = std::make_shared<sf::RenderWindow>(
		sf::VideoMode(1000, 600),
		"FlappyBird",
		sf::Style::Titlebar | sf::Style::Close
		);
	renderWindow->setFramerateLimit(60);
	renderWindow->setPosition(sf::Vector2i(0, 0));
	

	//set obstacles
	bottomObstacle.setScale(1.5f, 1.5f);
	bottomObstacle.setPosition(100, 200);

	topObstacle.setScale(1.5f, -1.5f);
	topObstacle.setPosition(100, 100);


};

void Game::run() {
	while (renderWindow->isOpen()) {
		events();
		draw();
	}
}

void Game::events() {
	auto event = std::make_shared<sf::Event>();
	while (renderWindow->pollEvent(*event)) {
		if (event->type == Event::Closed) {
			renderWindow->close();
		}
	}
}

void Game::draw() {
	renderWindow->clear(Color::Black);
	renderWindow->draw(*background.getSprite());
	renderWindow->draw(*bird.getSprite());
	renderWindow->draw(*bottomObstacle.getSprite());
	renderWindow->draw(*topObstacle.getSprite());
	renderWindow->display();
}