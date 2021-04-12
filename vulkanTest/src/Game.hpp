#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>

class Game
{
private:
    GLFWwindow *m_window;
    VkInstance m_vkInstance;

    void initWindow();

    void createVulkanInstance();
    void initVulkan();

    void mainLoop();
    void cleanup();

public:
    Game();
    ~Game();
    void run();
};