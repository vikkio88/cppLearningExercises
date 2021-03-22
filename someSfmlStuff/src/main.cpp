#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using Shapes = std::vector<sf::Shape *>;

void addCircle(Shapes &shapes, sf::Vector2i clickPosition)
{
    auto circle = new sf::CircleShape(10);
    circle->setOrigin(10, 10);
    circle->setFillColor(sf::Color::White);
    circle->setPosition(clickPosition.x, clickPosition.y);

    shapes.push_back(circle);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    Shapes shapes;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            auto pos = sf::Mouse::getPosition(window);
            addCircle(shapes, pos);
        }

        window.clear(sf::Color::Black);
        for (auto &s : shapes)
        {
            window.draw(*s);
        }
        window.display();
    }

    return EXIT_SUCCESS;
}