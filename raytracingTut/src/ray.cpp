#include "ray.hpp"

point3 ray::at(double t) const
{
    return m_origin + t * m_direction;
}