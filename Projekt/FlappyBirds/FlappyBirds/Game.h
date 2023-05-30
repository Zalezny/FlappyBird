#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game {
	shared_ptr<RenderWindow> window;
	double gravity, frame, space;
	Texture backgroundTexture, birdTexture, pipeTexture;
	shared_ptr<Sprite> backgroundSprite, birdSprite, pipeBottomSprite, pipeTopSprite;
public:
	Game();
	void run();

};