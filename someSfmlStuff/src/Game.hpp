#pragma once

#include "Window.hpp"
#include "SceneManager.hpp"

#include <vector>

class Game
{
private:
    Window m_Window;
    sf::Clock m_Clock;
    SceneManager m_SceneManager;

public:
    Game();
    Game(const std::string &name);

    void run();
};
