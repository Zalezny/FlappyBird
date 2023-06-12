#include <iostream>
#include "RenderWindowSingleton.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Positions {
public:
	static Vector2f getCenter(FloatRect bounds);
};