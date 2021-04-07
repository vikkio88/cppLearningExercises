#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

int main()
{
    sf::RenderWindow window{{800, 600}, "TGUI window with SFML"};
    tgui::GuiSFML gui{window};

    auto button = std::make_shared<tgui::Button>();
    button->setText("Test Button");
    button->setPosition(400 - (button->getSize().x / 2), 300);

    button->onClick([]() { std::cout << "Clicked\n"; });

    gui.add(button);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        gui.draw();
        window.display();
    }

    return EXIT_SUCCESS;
}