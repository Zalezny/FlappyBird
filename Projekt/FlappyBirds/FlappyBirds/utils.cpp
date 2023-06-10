#include "utils.h"

bool Utils::isSpriteClicked(sf::Sprite* sprite, std::shared_ptr<sf::RenderWindow> window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (sprite->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
        {
            return true;
        }
        return false;
    }
}