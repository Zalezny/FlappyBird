#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game {
	shared_ptr<RenderWindow> window;
	double gravity, frame, space;
	Texture background, bird, pipe;
	Sprite background, bird, pipe;
public:
	Game();
	void run();

};