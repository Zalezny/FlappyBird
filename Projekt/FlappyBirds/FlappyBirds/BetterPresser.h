#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;
using namespace sf;

class BetterPresser {
	atomic<bool> isButtonClicked;
	thread threadHandler;
	void handler();
public:
	BetterPresser();
	bool handleClickKey(Keyboard::Key keyboardBtn);
};