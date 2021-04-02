#include "Game.hpp"
#include "GameState.hpp"
#include "helpers.hpp"

#include <SFML/Graphics.hpp>

Game::Game() : m_Window(sf::VideoMode(800, 600), "Test")
{
}

void Game::run()
{

    auto gameState = GameState::getInstance();

    while (m_Window.isOpen())
    {
        sf::Event event;
        auto lines = *(gameState->lines);
        auto shapes = *(gameState->shapes);

        while (m_Window.pollEvent(event))
        {
            handleEvent(event, m_Window);
        }

        m_Window.clear(sf::Color::Black);

        for (auto &s : shapes)
        {
            m_Window.draw(*s);
        }

        for (auto &l : lines)
        {
            m_Window.draw(*l);
        }

        m_Window.display();
    }
}
