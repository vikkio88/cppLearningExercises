#include "Game.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <algorithm>

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

void Game::createVulkanInstance()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &m_vkInstance) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create instance!");
    }

    // Getting extensions
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    std::cout << "glfw required extensions:\n";
    for (size_t i = 0; i < glfwExtensionCount; i++)
    {
        auto currentExt = glfwExtensions[i];
        std::cout << '\t' << currentExt << '\n';
        auto result = std::find_if(
            extensions.begin(),
            extensions.end(),
            [&currentExt](auto &ext) { return ext.extensionName == currentExt; });

        if (result != extensions.end())
            std::cout << "\t\tnot found!\n";
        else
            std::cout << "\t\tsupported\n";
    }
}

void Game::initVulkan()
{
    createVulkanInstance();
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
    vkDestroyInstance(m_vkInstance, nullptr);
    glfwDestroyWindow(m_window);

    glfwTerminate();
}