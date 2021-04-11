#include <iostream>
#define GLEW_STATIC

#include <SFML/Graphics.hpp>

#include <GL/glew.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    // OpenGl Version => glxinfo | grep "OpenGL version"
    // 4.6 on my laptop
    settings.majorVersion = 4;
    settings.minorVersion = 6;
    settings.attributeFlags = sf::ContextSettings::Core;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "GlewTest", sf::Style::Titlebar, settings);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Problems initialising GLEW/OPENGL\n";
        return EXIT_FAILURE;
    }
    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        glClearColor(0.1f, 0.2f, 0.3f, .9f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.display();
    }

    std::cout << "\n\nBye, have a good time\n";
    return EXIT_SUCCESS;
}