#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

struct ShaderSource
{
    std::string vertex;
    std::string fragment;
};

enum class ShaderType
{
    Vertex = GL_VERTEX_SHADER,
    Fragment = GL_FRAGMENT_SHADER
};

void messageCallback(GLenum source, GLenum type, unsigned int x, unsigned int y, int z, const char *a, const void *b);
void framebufferSizeCallback(GLFWwindow *window, int width, int height);

ShaderSource load(const std::string &name);
unsigned int createShader(ShaderType type, const std::string &source);