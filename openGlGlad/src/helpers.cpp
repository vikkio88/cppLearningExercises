#include "helpers.hpp"

#include <iostream>

void messageCallback(GLenum source, GLenum type, unsigned int x, unsigned int y, int z, const char *a, const void *b)
{
    std::cout << "ERROR: " << source << " " << type << " " << x << " " << y << " " << z << " " << a << " " << b << " " << std::endl;
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
