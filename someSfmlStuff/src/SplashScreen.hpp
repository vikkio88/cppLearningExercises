#pragma once

#include "Scene.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class SplashScreen : public Scene
{
private:
    std::unique_ptr<sf::CircleShape> m_Circle;

public:
    SplashScreen() : Scene("splashScreen") {}
    void onCreate() override;
    void onDestroy() override;

    void onActivate() override;
    void onDeactivate() override;

    void processInput() override;
    void update(float dt) override;
    void draw(Window &window) override;
};
