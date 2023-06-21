#include "RenderWindowSingleton.h"

RenderWindowSingleton* RenderWindowSingleton::singleton = nullptr;;

RenderWindowSingleton *RenderWindowSingleton::GetInstance() {
    if (singleton == nullptr) {
        std::shared_ptr<sf::RenderWindow> renderWindow = std::make_shared<sf::RenderWindow>(
            sf::VideoMode(1000, 600),
            "FlappyBird",
            sf::Style::Titlebar | sf::Style::Close
            );
        singleton = new RenderWindowSingleton(renderWindow);
    }
    return singleton;
}