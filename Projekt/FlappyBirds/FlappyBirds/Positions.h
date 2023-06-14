#include <iostream>
#include "RenderWindowSingleton.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Positions {
public:
	static Vector2f getCenter(FloatRect bounds, float posY = 0.5, float posX = 0.5);
	static Vector2f getTopRight(FloatRect bounds, float margin);
};