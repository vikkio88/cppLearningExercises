#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "helpers.hpp"
#include "GameState.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    auto gameState = GameState::getInstance();

    while (window.isOpen())
    {
        sf::Event event;
        auto lines = *(gameState->lines);
        auto shapes = *(gameState->shapes);

        while (window.pollEvent(event))
        {
            handleEvent(event, window);
        }

        window.clear(sf::Color::Black);

        for (auto &s : shapes)
        {
            window.draw(*s);
        }

        for (auto &l : lines)
        {
            window.draw(*l);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}