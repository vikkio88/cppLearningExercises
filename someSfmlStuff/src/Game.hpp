#pragma once

#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow m_Window;

public:
    Game();

    void run();
};
