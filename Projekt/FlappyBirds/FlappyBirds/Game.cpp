#include "Game.h"

Game::Game() {
	window = make_shared<RenderWindow>(VideoMode(1000, 600), "FlappyBird", Style::Titlebar | Style::Close);
	window->setFramerateLimit(60);
	window->setPosition(Vector2i(0, 0));
	gravity = 0;
	frame = 0;
	space = 160.0;
};

void Game::run() {
	while (window->isOpen()) {

	}
}