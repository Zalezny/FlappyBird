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

	topObstacle.setScale(1.5f, -1.5f);


};

void Game::run() {
	while (renderWindow->isOpen()) {
		events();
		draw();
	}
	play();
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
	for (auto& o : obstacles) {
		renderWindow->draw(o);
	}
	renderWindow->display();
	bird.incrementPoints();
}

void Game::moveObstacles()
{
	if (bird.getPoints() % 150 == 0) {
		int position = rand() % 275 + 175;
		bottomObstacle.setPosition(1000, position + windowConfig.space);
		topObstacle.setPosition(1000, position);

		obstacles.push_back(*bottomObstacle.getSprite());
		obstacles.push_back(*topObstacle.getSprite());
	}

	for (size_t i = 0; i < obstacles.size(); i++) {
		if (obstacles[i].getPosition().x < -100) {
			obstacles.erase(obstacles.begin() + i);
		}
		obstacles[i].move(-3, 0);
	}
}

void Game::play()
{
	
}
