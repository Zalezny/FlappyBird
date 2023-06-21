#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class RenderWindowSingleton {
protected:
    RenderWindowSingleton(std::shared_ptr<sf::RenderWindow> renderWindow) : _value(renderWindow) {}
    std::shared_ptr<sf::RenderWindow> _value;
    static RenderWindowSingleton* singleton;

public:
    RenderWindowSingleton(RenderWindowSingleton& other) = delete;
    void operator=(const RenderWindowSingleton&) = delete;

    static RenderWindowSingleton* GetInstance();
    inline std::shared_ptr<sf::RenderWindow> value() const { return _value; };
   
};