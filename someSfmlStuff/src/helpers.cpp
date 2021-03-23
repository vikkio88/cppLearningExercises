#include <vector>
#include <iostream>

#include "helpers.hpp"
#include "GameState.hpp"
void addCircle(Shapes &shapes, sf::Vector2i clickPosition)
{
    auto circle = new sf::CircleShape(10);
    circle->setOrigin(10, 10);
    circle->setFillColor(sf::Color::White);
    circle->setPosition(clickPosition.x, clickPosition.y);

    shapes.push_back(circle);
}

void addLine(Lines &lines, sf::Vector2f p1, sf::Vector2f p2)
{
    auto line = new sf::VertexArray(sf::LinesStrip, 2);
    (*line)[0].position = p1;
    (*line)[0].color = sf::Color::White;
    (*line)[1].position = p2;
    (*line)[1].color = sf::Color::White;

    lines.push_back(line);
}

void handleEvent(sf::Event &event, sf::Window &window)
{
    if (event.type == sf::Event::Closed)
        window.close();

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        auto shapes = GameState::getInstance()->shapes;
        auto lines = GameState::getInstance()->lines;
        int size = shapes->size();
        auto shape1 = shapes->at(size - 1);
        auto shape2 = shapes->at(size - 2);
        if (size >= 2)
        {
            auto pos1 = shape1->getPosition();
            auto pos2 = shape2->getPosition();

            addLine(*lines, pos1, pos2);
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
    {
        auto shapes = GameState::getInstance()->shapes;
        std::cout << "Mouse " << event.mouseButton.button << std::endl
                  << "shapes: " << shapes->size() << std::endl;
        auto pos = sf::Mouse::getPosition(window);
        addCircle(*shapes, pos);
    }
}
