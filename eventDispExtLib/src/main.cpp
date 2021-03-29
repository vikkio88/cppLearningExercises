#include <iostream>

#include "EventDispatcher.hpp"

int main()
{
    std::cout << "YO" << std::endl;

    ed::EventDispatcher disp;

    disp.addListener("mario", []() { std::cout << "Mario\n"; });

    disp.dispatch(ed::Event("mario"));

    return EXIT_SUCCESS;
}