#pragma once

#include "Scene.hpp"
#include "Window.hpp"
#include "libs/helpers.hpp"

#include <SFML/Graphics.hpp>
#include <memory>



class GameScene : public Scene
{
private:
    Window &m_Window;
    DrawMode m_DrawMode;
    sf::Text m_Info;

    std::string getInfo();

public:
    GameScene(Window &window) : Scene("game"), m_Window(window), m_DrawMode(DrawMode::CIRCLE) {}

    virtual void onCreate() override;
    virtual void onDestroy() override;
    virtual void onActivate() override;
    virtual void onDeactivate() override;

    void processInput(sf::Event &event) override;
    void update(float dt) override;
    void draw(Window &window) override;
};
