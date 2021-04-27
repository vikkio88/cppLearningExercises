#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

int main()
{
    glm::vec2 v2(1.f, 2.f);
    /*
        | 1  2 |
        | 3  4 |
    seems like glm declares mat from vec using them as columns
    */
    glm::mat2 m1(glm::vec2(1, 3), glm::vec2(2, 4));
    std::cout << glm::to_string(m1 * v2) << std::endl;
    std::cout << glm::to_string(m1 * m1) << std::endl;
}