#include "TestGame.hpp"

#include "scenes/SplashScreen.hpp"
#include "scenes/GameScene.hpp"

TestGame::TestGame(const std::string &name) : Game(name)
{
    auto splash = std::make_shared<SplashScreen>(m_SceneManager);
    m_SceneManager.add(splash);

    auto gameScene = std::make_shared<GameScene>(m_Window);
    m_SceneManager.add(gameScene);
}