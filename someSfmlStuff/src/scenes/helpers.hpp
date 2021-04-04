#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using Shapes = std::vector<sf::Shape *>;
using Lines = std::vector<sf::VertexArray *>;

void handleEvent(sf::Event &event, sf::Vector2i& mousePos);
void addCircle(Shapes &shapes, sf::Vector2i clickPosition);
void addLine(Lines &lines, sf::Vector2f p1, sf::Vector2f p2);
void addLink(Shapes *shapes, Lines *lines);