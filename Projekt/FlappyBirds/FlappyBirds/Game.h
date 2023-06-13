#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "Bird.h"
#include "Obstacle.h"
#include "Background.h"
#include "WindowConfig.h"
#include "TextButton.h"
#include "MenuScreen.h"
#include "ScoreScreen.h"

using namespace std;
using namespace sf;

class Game {
	shared_ptr<RenderWindow> renderWindow;
	WindowConfig windowConfig;
	Bird bird;
	Obstacle bottomObstacle, topObstacle;
	Background background;
	vector<Sprite> obstacles;
	int count;
	bool gameover, isIncrementScore;
	Font font;
	Text scoreTxt, gameoverTxt;
	int score;
	TextButton menuButton;
	ScreenEnum screen;
	MenuScreen menuScreen;
	ScoreScreen scoreScreen;
	void mainEvents();
	void resetGame();
	void writeScore();

public:
	Game();
	void run();
	void events();
	void draw();
	void initDraw();
	void moveObstacles();
	void play();
	void animeBird();
	void moveBird();
	
};