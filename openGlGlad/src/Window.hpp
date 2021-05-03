#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
private:
    unsigned int m_width;
    unsigned int m_height;
    GLFWwindow *m_window;

public:
    Window(const std::string &name, unsigned int width, unsigned int height);
    ~Window();

    bool shouldClose();
    void processInput();
    void swapBuffers();
    void pollEvents();
};
