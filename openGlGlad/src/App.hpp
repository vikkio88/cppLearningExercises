#pragma once

#include "Window.hpp"
#include "Shader.hpp"

#include <string>
#include <memory>

class App
{
private:
    Window m_window;
    std::unique_ptr<Shader> shader;
    void init();
    void clear();
    void draw();

public:
    App(const std::string &name, unsigned int width, unsigned int height);

    void run();
};
