#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class Game
{
private:
    GLFWwindow *m_window;
    void initWindow();
    void initVulkan();
    void mainLoop();

    void cleanup();

public:
    Game();
    ~Game();
    void run();
};