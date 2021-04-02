#pragma once

#include <SFML/Graphics.hpp>

class Window
{
private:
    sf::RenderWindow m_Window;

public:
    Window(const std::string &title, int width, int height);
    bool isOpen();
    sf::Event getEvent();
    void startDraw();
    void draw(sf::Drawable &drawable);
    void endDraw();
};
