#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <cmath>

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb/stb_image.h"

#include "App.hpp"

void processInput(GLFWwindow *window);

int main()
{
    const unsigned int WIDTH = 800, HEIGHT = 600;
    App app("OpenGl - Tutorial", WIDTH, HEIGHT);

    app.run();

    return EXIT_SUCCESS;
}