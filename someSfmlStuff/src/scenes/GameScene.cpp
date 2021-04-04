#include "GameScene.hpp"
#include "state/GameState.hpp"
#include "libs/helpers.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

void GameScene::onCreate()
{
    std::cout << "creating " << m_Name << std::endl;
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
    auto mousePos = m_Window.getMousePosition();
    handleEvent(event, mousePos, m_DrawMode);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
    {
        m_DrawMode = m_DrawMode == DrawMode::CIRCLE ? DrawMode::SQUARE : DrawMode::CIRCLE;
        std::cout << "Changing Draw mode to " << m_DrawMode << "\n";
    }
}

void GameScene::update(float dt)
{
}
void GameScene::draw(Window &window)
{
    auto shapes = *(GameState::getInstance()->shapes);
    auto lines = *(GameState::getInstance()->lines);

    for (auto &s : shapes)
    {
        window.draw(*s);
    }

    for (auto &l : lines)
    {
        window.draw(*l);
    }
}