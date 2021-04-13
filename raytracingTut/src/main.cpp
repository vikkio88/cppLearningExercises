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

static int hits = 0;

void write_color(std::ostream &out, color pixel_color)
{
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

bool hit_sphere(const point3 &center, double radius, const ray &r)
{
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

color ray_color(const ray &r)
{
    if (hit_sphere(point3(0, 0, -22), 0.5, r))
    {
        hits++;
        return color(1, 0, 0);
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main()
{
    // Img setup
    const auto ratio = 16.0 / 9.;
    const int width = 400;
    const int height = static_cast<int>(width / ratio);

    // Camera setup
    auto viewportHeight = 2.0;
    auto viewportWidth = ratio * viewportHeight;
    auto focalLength = 1.0;

    auto origin = point3(0, 0, 0);
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
            auto v = double(j) / (height - 1);
            ray r(origin, lowerLeft + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\n\tCompleted\n\n";
    std::cerr << "\n\thits:" << hits << "\n\n";

    return EXIT_SUCCESS;
}