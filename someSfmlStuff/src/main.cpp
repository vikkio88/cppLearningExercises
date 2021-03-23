#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "helpers.hpp"
#include "GameState.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            handleEvent(event, window);
        }

        window.clear(sf::Color::Black);
        for (auto &s : *(GameState::getInstance()->shapes))
        {
            window.draw(*s);
        }

        for (auto &l : *(GameState::getInstance()->lines))
        {
            window.draw(*l);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}