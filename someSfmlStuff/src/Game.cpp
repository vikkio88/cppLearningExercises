#include "Game.hpp"
#include "scenes/SplashScreen.hpp"
#include "scenes/GameScene.hpp"

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

Game::Game(const std::string &name) : m_Window(name, 800, 600)
{
    auto splash = std::make_shared<SplashScreen>(m_SceneManager);
    m_SceneManager.add(splash);

    auto gameScene = std::make_shared<GameScene>(m_Window);
    m_SceneManager.add(gameScene);
}

void Game::run()
{
    while (m_Window.isOpen())
    {
        auto scene = m_SceneManager.getCurrent();
        auto dt = m_Clock.restart().asSeconds();        
        //std::cout << "FPS: " << 1 / dt << std::endl;

        auto event = m_Window.getEvent();

        if (scene != nullptr)
        {
            scene->processInput(event);
            scene->update(dt);
            m_Window.startDraw();
            scene->draw(m_Window);
            m_Window.endDraw();
        }
    }
}
