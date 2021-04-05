#pragma once

#include <SFML/Graphics.hpp>

namespace yoku
{
    class Window
    {
    private:
        sf::RenderWindow m_Renderer;
        int m_Width;
        int m_Height;

    public:
        Window(const std::string &title, int width, int height, sf::Uint32 style);
        bool isOpen();
        sf::RenderWindow &getRenderer();

        sf::Event getEvent();
        sf::Vector2i getMousePosition();
        int getWidth() { return m_Width; }
        int getHeight() { return m_Height; }

        void startDraw();
        void draw(sf::Drawable &drawable);
        void endDraw();
    };
}
