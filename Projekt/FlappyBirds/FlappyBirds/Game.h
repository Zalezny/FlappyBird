#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Obstacle.h"
#include "Background.h"
#include "WindowConfig.h"

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
	bool gameover;

public:
	Game();
	void run();
	void events();
	void draw();
	void moveObstacles();
	void play();
	void animeBird();
	void moveBird();
};