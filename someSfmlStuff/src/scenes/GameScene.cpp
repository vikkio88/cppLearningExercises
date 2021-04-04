#include "GameScene.hpp"
#include "GameState.hpp"
#include "helpers.hpp"

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
    handleEvent(event, mousePos);
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