#include "Application.hpp"

void Application::run()
{
    initVulkan();
    mainLoop();
    cleanup();
}

void Application::initVulkan()
{
}
void Application::mainLoop() {}
void Application::cleanup() {}