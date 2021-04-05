#include "GameScene.hpp"

#include "state/GameState.hpp"
#include "libs/helpers.hpp"

#include "yoku/Assets.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

std::string GameScene::getInfo()
{
    std::stringstream ss;
    auto shapes = *(GameState::getInstance()->shapes);
    auto lines = *(GameState::getInstance()->lines);
    ss << "Node Type: " << m_DrawMode << std::endl
       << "Nodes: " << shapes.size() << std::endl
       << "Arcs: " << lines.size();

    return ss.str();
}

void GameScene::onCreate()
{
    std::cout << "creating " << m_Name << std::endl;
    auto font = yoku::Assets::getInstance()->loadFont("callingcode");
    m_Info.setFont(*font);
    m_Info.setString(getInfo());
    m_Info.setCharacterSize(10);
    m_Info.setFillColor(sf::Color::White);
    m_Info.setPosition(10, 10);
}
void GameScene::onDestroy()
{
    std::cout << "destroying " << m_Name << std::endl;
}

void GameScene::onActivate()
{
    std::cout << "activating " << m_Name << std::endl;
}
void GameScene::onDeactivate()
{
    std::cout << "deactivating " << m_Name << std::endl;
}

void GameScene::processInput(sf::Event &event)
{
    m_hasChangedState = false;
    auto mousePos = m_Window.getMousePosition();
    m_hasChangedState = handleEvent(event, mousePos, m_DrawMode);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
    {
        m_DrawMode = m_DrawMode == DrawMode::CIRCLE ? DrawMode::SQUARE : DrawMode::CIRCLE;
        m_hasChangedState = true;
    }
}

void GameScene::update(float dt)
{
    if (m_hasChangedState)
    {
        m_Info.setString(getInfo());
    }
}

void GameScene::draw(yoku::Window &window)
{
    auto shapes = *(GameState::getInstance()->shapes);
    auto lines = *(GameState::getInstance()->lines);

    window.draw(m_Info);
    for (auto &s : shapes)
    {
        window.draw(*s);
    }

    for (auto &l : lines)
    {
        window.draw(*l);
    }
}