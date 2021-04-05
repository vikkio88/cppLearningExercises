#pragma once

#include <SFML/Graphics.hpp>

namespace yoku
{
    class Window
    {
    private:
        sf::RenderWindow m_Renderer;

    public:
        Window(const std::string &title, int width, int height, sf::Uint32 style);
        bool isOpen();
        sf::RenderWindow &getRenderer();

        sf::Event getEvent();
        sf::Vector2i getMousePosition();

        void startDraw();
        void draw(sf::Drawable &drawable);
        void endDraw();
    };
}
