#pragma once

#include "Scene.hpp"
#include "SceneManager.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class SplashScreen : public Scene
{
private:
    SceneManager &m_SceneManager;
    bool m_EnterPressed = false;
    sf::Font font;
    sf::Text title;

public:
    SplashScreen(SceneManager &sceneManager) : Scene("splashScreen"), m_SceneManager(sceneManager) {}
    void onCreate() override;
    void onDestroy() override;

    void onActivate() override;
    void onDeactivate() override;

    void processInput() override;
    void update(float dt) override;
    void draw(Window &window) override;
};
