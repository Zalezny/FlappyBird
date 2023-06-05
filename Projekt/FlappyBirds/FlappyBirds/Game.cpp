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

	gameover = false;
};

void Game::run() {
	while (renderWindow->isOpen()) {
		events();
		draw();
		play();
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
	for (auto& o : obstacles) {
		renderWindow->draw(o);
	}
	renderWindow->draw(*bird.getSprite());
	renderWindow->display();
	++count;
}

void Game::moveObstacles()
{
	if (Mouse::isButtonPressed(Mouse::Left)) {
		windowConfig.gravity = -8.f;
		bird.getSprite()->setRotation(-windowConfig.frame - 10.f);
	}
	else {
		bird.getSprite()->setRotation(windowConfig.frame - 10.f);
	}

	if (count % 150 == 0) {
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

void Game::animeBird() {
	windowConfig.frame += 0.15f;

	if (windowConfig.frame > 3) {
		windowConfig.frame -= 3;
	}

	bird.getSprite()->setTextureRect(sf::IntRect(34 * (int)windowConfig.frame, 0, 34, 24));
}

void Game::moveBird() {
	bird.getSprite()->move(0, windowConfig.gravity);
	windowConfig.gravity += 0.5f;
}

void Game::play()
{
	if (!gameover) {
		animeBird();
		moveBird();
		moveObstacles();
	}
}
