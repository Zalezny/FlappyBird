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
	isIncrementScore = false;

	//font
	font.loadFromFile("./resources/fonts/flappy_bird_font.ttf");
	gameoverTxt.setFont(font);
	gameoverTxt.setString("Press SPACE to restart");
	gameoverTxt.setPosition(200, 300);
	gameoverTxt.setCharacterSize(50);
	gameoverTxt.setOutlineThickness(3);

	//score
	score = 0;
	// score text
	scoreTxt.setFont(font);
	scoreTxt.setString(std::to_string(score));
	scoreTxt.setPosition(10, 10);
	scoreTxt.setCharacterSize(50);
	scoreTxt.setOutlineThickness(3);

	//first set 
	menu = true;
	game = false;
	textbtn = TextButton();
	

};

void Game::run() {
	while (renderWindow->isOpen()) {
		if (menu) {
			drawMenu();
			events();
		}
		if (game) {
			events();
			draw();
			if (!gameover)
				play();
		}
		
	}
	
}

void Game::drawMenu() {
	renderWindow->clear(Color::Black);
	renderWindow->draw(*background.getSprite());
	renderWindow->draw(*textbtn.getSprite());
	renderWindow->draw(textbtn.getText());
	renderWindow->display();
}

void Game::events() {
	auto event = std::make_shared<sf::Event>();
	while (renderWindow->pollEvent(*event)) {
		if (event->type == Event::Closed) {
			renderWindow->close();
		}
	}

	if (gameover && Keyboard::isKeyPressed(Keyboard::Space)) {
		score = 0;
		scoreTxt.setString(std::to_string(score));
		obstacles.clear();

		bird.setPosition(
			500.f - bird.getX() / 2.f,
			300.f - bird.getY() / 2.f
		);
		gameover = false;
	}
}

void Game::draw() {
	renderWindow->clear(Color::Black);
	renderWindow->draw(*background.getSprite());
	for (auto& o : obstacles) {
		renderWindow->draw(o);
	}
	renderWindow->draw(*bird.getSprite());

	if (gameover) {
		renderWindow->draw(gameoverTxt);
	}
	renderWindow->draw(scoreTxt);
	renderWindow->display();
	++count;
}

void Game::moveObstacles()
{

	if (count % 150 == 0) {
		int position = rand() % 275 + 175;
		bottomObstacle.setPosition(1000, position + windowConfig.space);
		topObstacle.setPosition(1000, position);

		obstacles.push_back(*bottomObstacle.getSprite());
		obstacles.push_back(*topObstacle.getSprite());
	}

	//check every obstacle is granted to points
	for (size_t i = 0; i < obstacles.size(); i++) {
		if (obstacles[i].getGlobalBounds().intersects(bird.getSprite()->getGlobalBounds())) {
			gameover = true;
		}

		if (obstacles[i].getPosition().x < -100) {
			obstacles.erase(obstacles.begin() + i);
		}
		obstacles[i].move(-3, 0);

		if (obstacles[i].getPosition().x == 298 && !isIncrementScore) {
			scoreTxt.setString(std::to_string(++score));
			isIncrementScore = true;
		}
		else {
			isIncrementScore = false;
		}
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

	if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space)) {
		windowConfig.gravity = -4.f;
		bird.getSprite()->setRotation(-windowConfig.frame - 10.f);
	}
	else {
		bird.getSprite()->setRotation(windowConfig.frame - 10.f);
	}

	//when bird is outside the screen
	if (bird.getSprite()->getPosition().y  < 0 || bird.getSprite()->getPosition().y > renderWindow->getSize().y) {
		gameover = true;
	}
}

void Game::play()
{
	animeBird();
	moveBird();
	moveObstacles();
}
