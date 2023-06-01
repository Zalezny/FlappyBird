#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"

using namespace std;
using namespace sf;

class Game {
	shared_ptr<RenderWindow> window;
	double gravity, frame, space;
	Bird bird;
	Texture backgroundTexture, pipeTexture;
	shared_ptr<Sprite> backgroundSprite,  pipeBottomSprite, pipeTopSprite;
public:
	Game();
	void run();

};