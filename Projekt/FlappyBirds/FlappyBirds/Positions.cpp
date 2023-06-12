#include "Positions.h"


Vector2f Positions::getCenter(FloatRect bounds) {
	shared_ptr<RenderWindow> renderWindow = RenderWindowSingleton::GetInstance()->value();
	float x = (renderWindow->getSize().x - bounds.width) * 0.5;
	float y = (renderWindow->getSize().y - bounds.height) * 0.5;
	return Vector2f(x, y);
}
