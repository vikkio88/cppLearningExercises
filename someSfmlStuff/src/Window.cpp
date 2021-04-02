#include "Window.hpp"

Window::Window(const std::string &title, int widht, int height)
    : m_Window(sf::VideoMode(800, 600), "Test", sf::Style::None || sf::Style::Fullscreen)
{
}

bool Window::isOpen()
{
    return m_Window.isOpen();
}

sf::Event Window::getEvent()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
            m_Window.close();

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            m_Window.close();
        }

        return event;
    }
}

void Window::startDraw()
{
    m_Window.clear(sf::Color::Black);
}

void Window::draw(sf::Drawable &drawable)
{
    m_Window.draw(drawable);
}

void Window::endDraw()
{
    m_Window.display();
}