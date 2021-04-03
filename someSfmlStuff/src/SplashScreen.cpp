#include "SplashScreen.hpp"
#include "Window.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

void SplashScreen::onCreate()
{
    std::cout << "creating " << m_Name << std::endl;

    const int CIRCLE_RADIUS = 20;
    m_Circle = std::make_unique<sf::CircleShape>(CIRCLE_RADIUS);
    m_Circle->setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);
    m_Circle->setFillColor(sf::Color::White);
    m_Circle->setPosition(100, 100);
}
void SplashScreen::onDestroy()
{
    std::cout << "destroying " << m_Name << std::endl;
}

void SplashScreen::onActivate()
{
    std::cout << "activating " << m_Name << std::endl;
}
void SplashScreen::onDeactivate()
{
    std::cout << "deactivating " << m_Name << std::endl;
}

void SplashScreen::processInput()
{
}
void SplashScreen::update(float dt)
{
}
void SplashScreen::draw(Window &window)
{
    window.draw(*m_Circle);
}