#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Obstacle.h"

using namespace std;
using namespace sf;

class Game {
	shared_ptr<RenderWindow> window;
	double gravity, frame, space;
	Bird bird;
	Obstacle bottomObstacle, topObstacle;
	Texture backgroundTexture;
	shared_ptr<Sprite> backgroundSprite;
public:
	Game();
	void run();

};