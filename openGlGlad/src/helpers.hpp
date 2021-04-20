#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

struct ShaderSource
{
    std::string vertex;
    std::string fragment;
};

enum ShaderType
{
    Vertex = 0,
    Fragment = 1
};
constexpr GLenum shaderTypesMap[] = {GL_VERTEX_SHADER, GL_FRAGMENT_SHADER};

void messageCallback(GLenum source, GLenum type, unsigned int x, unsigned int y, int z, const char *a, const void *b);
void framebufferSizeCallback(GLFWwindow *window, int width, int height);

ShaderSource loadShaderSources(const std::string &name);
unsigned int createShader(ShaderType type, const std::string &source);
unsigned int createProgram(unsigned int vertexShader, unsigned int fragmentShader);
