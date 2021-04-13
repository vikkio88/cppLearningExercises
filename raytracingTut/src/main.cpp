#include <iostream>

#include "Vec3.hpp"

/*
PPM files style
# P3 <- start with this
# col row
# color 3 number of 0-255
P3
3 2
255
0 255 0  0 255 0  0 255 0
0 255 0  0 255 0  0 255 0 
*/

int main()
{
    const int WIDTH = 1000;
    const int HEIGHT = 1000;
    std::cout << "P3\n"
              << WIDTH << ' ' << HEIGHT << "\n255\n";
    for (int j = HEIGHT - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < WIDTH; ++i)
        {
            colour c(
                double(i) / (WIDTH - 1),
                double(j) / (HEIGHT - 1),
                .25);
            printColour(std::cout, c);
        }
    }
    std::cerr << "\n\tCompleted\n\n";
    return EXIT_SUCCESS;
}