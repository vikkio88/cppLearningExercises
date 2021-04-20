#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

#include "helpers.hpp"

void processInput(GLFWwindow *window);

int main()
{
    glfwInit();

    // this was breaking the world
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    // glxinfo | grep "OpenGL version"
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const uint32_t WIDTH = 800, HEIGHT = 600;
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGl - Tutorial", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return EXIT_FAILURE;
    }
    glViewport(0, 0, WIDTH, HEIGHT);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(&messageCallback, 0);

    auto sources = loadShaderSources("triangle");

    // defining the vertex shader code
    unsigned int vertexShader = createShader(ShaderType::Vertex, sources.vertex);
    // defining the fragment shader code
    unsigned int fragmentShader = createShader(ShaderType::Fragment, sources.fragment);

    //creating program
    unsigned int shaderProgram = createProgram(vertexShader, fragmentShader);

    //shaders
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f};

    //creating vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // pushing data so shaders can use it
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    unsigned int vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    //LOOP
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(.8f, .5f, .3f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        //using the program
        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        // draw points 0-3 from the currently bound VAO with current in-use shader
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // removing shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // clearing up window
    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}