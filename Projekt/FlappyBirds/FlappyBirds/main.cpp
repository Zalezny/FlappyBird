#include "Game.h"
#include "FileReader.h"

int main() {
	Game game = Game();
	game.run();
	srand(time(0));
	return 0;
}