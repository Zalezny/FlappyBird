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
#include "HelpScreen.h"
#include "BetterPresser.h"
#include "Screen.h"

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
	bool gameover, isIncrementScore, pause;
	Font font;
	Text scoreTxt, gameoverTxt, pauseTxt;
	int score;
	TextButton menuButton;
	ScreenEnum screen;
	Screen* menuScreen;
	Screen* scoreScreen;
	Screen* helpScreen;

	BetterPresser pausePresser;
	shared_ptr<Event> event;
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