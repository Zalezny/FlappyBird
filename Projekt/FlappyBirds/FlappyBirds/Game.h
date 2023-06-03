#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Obstacle.h"
#include "Background.h"

using namespace std;
using namespace sf;

class Game {
	shared_ptr<RenderWindow> window;
	double gravity, frame, space;
	Bird bird;
	Obstacle bottomObstacle, topObstacle;
	Background background;
public:
	Game();
	
	void run();
	void events();
	void draw();

};