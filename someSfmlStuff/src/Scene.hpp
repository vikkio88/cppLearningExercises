#pragma once

#include "Window.hpp"

#include <string>

class Scene
{
private:
    std::string m_Name;

public:
    bool isActive;
    Scene();
    virtual void onCreate() = 0;
    virtual void onDestroy() = 0;

    virtual void onActivate(){};
    virtual void onDeactivate(){};

    virtual void processInput(){};
    virtual void update(float deltaTime){};
    virtual void draw(Window &window){};
};
