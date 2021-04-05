#pragma once

#include "yoku/Assets.hpp"
#include "yoku/SceneManager.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class SplashScreen : public yoku::Scene
{
private:
    yoku::SceneManager &m_SceneManager;
    bool m_EnterPressed = false;
    sf::Text title;
    int m_W;
    int m_H;

public:
    SplashScreen(yoku::SceneManager &sceneManager, int width, int height) : Scene("splashScreen"), m_SceneManager(sceneManager), m_W(width), m_H(height) {}
    void onCreate() override;
    void onDestroy() override;

    void onActivate() override;
    void onDeactivate() override;

    void processInput(sf::Event &event) override;
    void update(float dt) override;
    void draw(yoku::Window &window) override;
};
