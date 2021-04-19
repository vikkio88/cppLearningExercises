#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void messageCallback(GLenum source, GLenum type, unsigned int x, unsigned int y, int z, const char *a, const void *b);
void framebufferSizeCallback(GLFWwindow *window, int width, int height);