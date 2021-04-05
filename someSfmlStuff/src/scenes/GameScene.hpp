#pragma once

#include "yoku/Scene.hpp"
#include "yoku/Window.hpp"

#include "libs/helpers.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class GameScene : public yoku::Scene
{
private:
    yoku::Window &m_Window;
    DrawMode m_DrawMode;
    sf::Text m_Info;
    sf::Text m_Tutorial;
    bool m_hasChangedState = false;

    std::string getInfo();

public:
    GameScene(yoku::Window &window) : Scene("game"), m_Window(window), m_DrawMode(DrawMode::CIRCLE) {}

    virtual void onCreate() override;
    virtual void onDestroy() override;
    virtual void onActivate() override;
    virtual void onDeactivate() override;

    void processInput(sf::Event &event) override;
    void update(float dt) override;
    void draw(yoku::Window &window) override;
};
