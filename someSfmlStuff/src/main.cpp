#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using Shapes = std::vector<sf::Shape *>;
using Lines = std::vector<sf::VertexArray *>;

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

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    Shapes shapes;
    Lines lines;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                std::cout << "Closing" << std::endl;
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                int size = shapes.size();
                if (size >= 2)
                {
                    auto pos1 = shapes[size - 1]->getPosition();
                    auto pos2 = shapes[size - 2]->getPosition();

                    addLine(lines, pos1, pos2);
                }
                else
                {
                    std::cout << "Nope, there are only" << size << " shapes in, need >=2" << std::endl;
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                auto pos = sf::Mouse::getPosition(window);
                addCircle(shapes, pos);
            }
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