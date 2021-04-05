#include "TestGame.hpp"

#include "scenes/SplashScreen.hpp"
#include "scenes/GameScene.hpp"
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 600;
TestGame::TestGame(const std::string &name) : Game(name, WINDOW_WIDTH, WINDOW_HEIGHT)
{
    auto splash = std::make_shared<SplashScreen>(m_SceneManager, WINDOW_WIDTH, WINDOW_HEIGHT);
    m_SceneManager.add(splash);

    auto gameScene = std::make_shared<GameScene>(m_Window);
    m_SceneManager.add(gameScene);
}