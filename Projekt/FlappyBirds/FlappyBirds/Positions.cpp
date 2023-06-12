#include "Positions.h"


Vector2f Positions::getCenter(FloatRect bounds, float posY, float posX) {
	shared_ptr<RenderWindow> renderWindow = RenderWindowSingleton::GetInstance()->value();
	float x = (renderWindow->getSize().x - bounds.width) * posX;
	float y = (renderWindow->getSize().y - bounds.height) * posY;
	return Vector2f(x, y);
}
