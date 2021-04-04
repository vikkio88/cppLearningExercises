#include <vector>
#include <iostream>

#include "helpers.hpp"
#include "../state/GameState.hpp"

const int CIRCLE_RADIUS = 5;
void addNode(Shapes &shapes, sf::Vector2i clickPosition, DrawMode drawMode)
{
    sf::Shape *node = nullptr;
    if (drawMode == DrawMode::CIRCLE)
    {
        node = new sf::CircleShape(CIRCLE_RADIUS);
        node->setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);
    }
    else
    {
        node = new sf::RectangleShape(sf::Vector2f(CIRCLE_RADIUS * 2, CIRCLE_RADIUS * 2));
        node->setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);
    }

    node->setFillColor(sf::Color::White);
    node->setPosition(clickPosition.x, clickPosition.y);

    shapes.push_back(node);
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

void handleEvent(sf::Event &event, sf::Vector2i &mousePos, DrawMode drawMode)
{

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        auto shapes = GameState::getInstance()->shapes;
        auto lines = GameState::getInstance()->lines;
        std::cout << "Lines: " << lines->size() << std::endl
                  << "Shapes: " << shapes->size() << std::endl;
    }
    else if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
    {
        auto shapes = GameState::getInstance()->shapes;
        auto lines = GameState::getInstance()->lines;
        addNode(*shapes, mousePos, drawMode);
        addLink(shapes, lines);
    }
}

void addLink(Shapes *shapes, Lines *lines)
{
    int size = shapes->size();
    if (size >= 2)
    {
        auto shape1 = shapes->at(size - 1);
        auto shape2 = shapes->at(size - 2);
        auto pos1 = shape1->getPosition();
        auto pos2 = shape2->getPosition();

        addLine(*lines, pos1, pos2);
    }
}

std::ostream &operator<<(std::ostream &stream, DrawMode drawMode)
{

    switch (drawMode)
    {
    case 0:
    {

        stream << "CIRCLE";
        return stream;
    }
    case 1:
    {

        stream << "SQUARE";
        return stream;
    }

    default:
        break;
    }

    return stream;
}
