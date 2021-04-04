#pragma once

#include "Scene.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class GameScene : public Scene
{
private:
    std::unique_ptr<sf::CircleShape> m_Circle;

public:
    GameScene() : Scene("game") {}

    virtual void onCreate() override;
    virtual void onDestroy() override;
    virtual void onActivate() override;
    virtual void onDeactivate() override;

    void processInput() override;
    void update(float dt) override;
    void draw(Window &window) override;
};
