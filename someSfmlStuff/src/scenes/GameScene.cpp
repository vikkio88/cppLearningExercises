#include "GameScene.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

void GameScene::onCreate()
{
    std::cout << "creating " << m_Name << std::endl;

    const int CIRCLE_RADIUS = 20;
    m_Circle = std::make_unique<sf::CircleShape>(CIRCLE_RADIUS);
    m_Circle->setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);
    m_Circle->setFillColor(sf::Color::White);
    m_Circle->setPosition(100, 100);
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

void GameScene::processInput()
{
}

void GameScene::update(float dt)
{
}
void GameScene::draw(Window &window)
{
    window.draw(*m_Circle);
}