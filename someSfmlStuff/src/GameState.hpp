#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using Shapes = std::vector<sf::Shape *>;
using Lines = std::vector<sf::VertexArray *>;

class GameState
{
public:
    Shapes* shapes;
    Lines* lines;

public:
    static GameState *getInstance()
    {
        if (instance == 0)
            instance = new GameState();
        return instance;
    }

private:
    static GameState *instance;
    GameState();
};
