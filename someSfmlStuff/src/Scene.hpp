#pragma once

#include "Window.hpp"

#include <string>

class Scene
{
protected:
    std::string m_Name;

public:
    bool isActive;
    Scene(const std::string &name) : m_Name(name) {}
    std::string getName() const { return m_Name; }
    virtual void onCreate() = 0;
    virtual void onDestroy() = 0;

    virtual void onActivate(){};
    virtual void onDeactivate(){};

    virtual void processInput(){};
    virtual void update(float dt){};
    virtual void draw(Window &window){};
};
