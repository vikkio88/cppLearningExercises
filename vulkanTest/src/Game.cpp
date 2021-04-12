#include "Game.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800, HEIGHT = 600;

Game::Game() {}
void Game::run()
{
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void Game::initWindow()
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

Game::~Game()
{
    // this is done in cleanp atm
    //delete m_window;
}

void Game::initVulkan()
{
}
void Game::mainLoop()
{
    while (!glfwWindowShouldClose(m_window))
    {
        glfwPollEvents();
    }
}
void Game::cleanup()
{
    glfwDestroyWindow(m_window);

    glfwTerminate();
}