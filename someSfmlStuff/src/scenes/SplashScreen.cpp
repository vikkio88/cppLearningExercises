#include "SplashScreen.hpp"
#include "Window.hpp"
#include "Assets.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

void SplashScreen::onCreate()
{
    std::cout << "creating " << m_Name << std::endl;

    // Loading font, might be delegated to resource singleton?
    auto font = Assets::getInstance()->loadFont("callingcode");
    title.setFont(*font);
    title.setString("Press [ENTER] to start");
    title.setCharacterSize(24);
    title.setFillColor(sf::Color::White);
    title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
    title.setPosition(400, 300);
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

void SplashScreen::processInput(sf::Event &event)
{
    m_EnterPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
}

void SplashScreen::update(float dt)
{
    if (m_EnterPressed)
    {
        m_SceneManager.switchTo("game");
    }
}
void SplashScreen::draw(Window &window)
{
    window.draw(title);
}