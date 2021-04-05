#pragma once

#include "SceneManager.hpp"
#include "Window.hpp"

#include <vector>
#include <string>

namespace yoku
{
    class Game
    {
    protected:
        std::string m_Name;
        Window m_Window;
        sf::Clock m_Clock;
        SceneManager m_SceneManager;
        int m_Width;
        int m_Height;

    public:
        Game(
            const std::string &name,
            int width = 800,
            int height = 600,
            sf::Uint32 style = sf::Style::Titlebar)
            : m_Window(name, width, height, style), m_Name(name), m_Width(width), m_Height(height)
        {
        }

        virtual void run();
    };
}
