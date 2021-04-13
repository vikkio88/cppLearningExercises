#include <iostream>

#include "vec3.hpp"
#include "ray.hpp"

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

void printColour(std::ostream &out, colour &col)
{
    out << static_cast<int>(255.999 * col.x()) << ' '
        << static_cast<int>(255.999 * col.y()) << ' '
        << static_cast<int>(255.999 * col.z())
        << '\n';
}

colour rayColour(const ray &r)
{
    vec3 uDirection = unit_vector(r.direction());
    auto t = .5 * (uDirection.y() + 1.0);
    return (1. - t) * colour(1., 1., 1.) + t * colour(.5, .7, 1.);
}

int main()
{
    // Img setup
    const auto ratio = 16.0 / 9.;
    const int width = 600;
    const int height = static_cast<int>(width / ratio);

    // Camera setup
    auto viewportHeight = 2.;
    auto viewportWidth = ratio * viewportHeight;
    auto focalLength = 1.;

    auto origin = point3();
    auto horizontal = vec3(viewportWidth, 0, 0);
    auto vertical = vec3(0, viewportHeight, 0);

    auto lowerLeft = origin - (horizontal / 2) - (vertical / 2) - vec3(0, 0, focalLength);

    // Rendering
    std::cout << "P3\n"
              << width << ' ' << height << "\n255\n";
    for (int j = height - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i)
        {
            auto u = double(i) / (width - 1);
            auto v = double(i) / (height - 1);

            ray r(origin, lowerLeft + u * horizontal + v * vertical - origin);
            colour c = rayColour(r);
            printColour(std::cout, c);
        }
    }
    std::cerr << "\n\tCompleted\n\n";
    return EXIT_SUCCESS;
}