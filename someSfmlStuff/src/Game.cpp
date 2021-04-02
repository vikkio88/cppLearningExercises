#include "Game.hpp"
#include "GameState.hpp"
#include "helpers.hpp"

#include <SFML/Graphics.hpp>

Game::Game(const std::string &name) : m_Window(name, 800, 600)
{
}

void Game::run()
{

    auto gameState = GameState::getInstance();

    while (m_Window.isOpen())
    {
        auto lines = *(gameState->lines);
        auto shapes = *(gameState->shapes);
        auto event = m_Window.getEvent();
        handleEvent(event);

        m_Window.startDraw();
        for (auto &s : shapes)
        {
            m_Window.draw(*s);
        }

        for (auto &l : lines)
        {
            m_Window.draw(*l);
        }
        m_Window.endDraw();
    }
}
