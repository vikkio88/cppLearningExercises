#pragma once

#include "Window.hpp"

#include <vector>

class Game
{
private:
    Window m_Window;
    //std::vector<Scene> m_Scenes;

public:
    Game();
    Game(const std::string &name);

    void run();
};
