#include "Game.h"
#include "RenderWindowSingleton.h"

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
	renderWindow = RenderWindowSingleton::GetInstance()->value();
	renderWindow->setFramerateLimit(60);
	renderWindow->setPosition(sf::Vector2i(0, 0));
	
	//set obstacles
	bottomObstacle.setScale(1.5f, 1.5f);
	topObstacle.setScale(1.5f, -1.5f);

	gameover = false;
	isIncrementScore = false;
	pause = false;

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

	//pause text
	pauseTxt.setFont(font);
	pauseTxt.setString("||");
	pauseTxt.setPosition(Positions::getTopRight(pauseTxt.getGlobalBounds(), 10));
	pauseTxt.setCharacterSize(50);
	pauseTxt.setOutlineThickness(1);

	//first set screen (it's useful for debugging)
	screen = ScreenEnum::MENU;

	//menu btn
	menuButton = TextButton();

	//screens
	menuScreen = MenuScreen();
	scoreScreen = ScoreScreen();
	
};

void Game::run() {
	while (renderWindow->isOpen()) {
		if (renderWindow->hasFocus()) {
			mainEvents();
			switch (screen)
			{
			case ScreenEnum::PLAY:
				events();
				draw();
				if (!gameover && !pause)
					play();
				break;
			case ScreenEnum::MENU:
				initDraw();
				menuScreen.show(&screen);
				break;
			case ScreenEnum::SCORE:
				initDraw();
				scoreScreen.show(&screen);
				break;
			case ScreenEnum::HELP:
				break;
			default:
				break;
			}
		}
	}
}

void Game::mainEvents() {
	auto event = std::make_shared<sf::Event>();
	while (renderWindow->pollEvent(*event)) {
		if (event->type == Event::Closed) {
			renderWindow->close();
		}
	}
}

void Game::initDraw() {
	resetGame();
	renderWindow->clear(Color::Black);
	renderWindow->draw(*background.getSprite());
}


void Game::events() {
	if (gameover && Keyboard::isKeyPressed(Keyboard::Space)) {
		resetGame();
	}

	if (gameover && menuButton.isButtonClicked(renderWindow)) {
		screen = ScreenEnum::MENU;
	}

	if (pausePresser.handleClickKey(Keyboard::P)) {
		pause = !pause;
	}
}

void Game::resetGame() {
	score = 0;
	scoreTxt.setString(std::to_string(score));
	obstacles.clear();

	bird.setPosition(
		500.f - bird.getX() / 2.f,
		300.f - bird.getY() / 2.f
	);
	gameover = false;
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
		menuButton.show("Menu", Vector2f(renderWindow->getSize().x * 0.4, renderWindow->getSize().y * 0.6));
	}
	if (pause) {
		pauseTxt.setString("<");
	}
	else {
		pauseTxt.setString("||");
	}
	renderWindow->draw(scoreTxt);
	renderWindow->draw(pauseTxt);
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
			writeScore();
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
		writeScore();
	}
}

void Game::play()
{
	animeBird();
	moveBird();
	moveObstacles();
}

void Game::writeScore()
{
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	tm localTime;
	localtime_s(&localTime, &currentTime);

	ostringstream oss;
	oss << put_time(&localTime, "%H:%M %d-%m-%Y");

	string formattedDateTime = oss.str();

	ScoreEntity scoreEntity = ScoreEntity(score, formattedDateTime);
	FileReader().writeScore(scoreEntity);
}