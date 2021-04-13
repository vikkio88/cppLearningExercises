#include "Vec3.hpp"

vec3 vec3::operator-() const
{
    return vec3(-x(), -y(), -z());
}

double vec3::operator[](int i) const
{
    if (i > 2)
        return 0.;

    return m_e[i];
}

double &vec3::operator[](int i)
{
    return m_e[i];
}

vec3 &vec3::operator+(const vec3 &other)
{
    m_e[0] += other.x();
    m_e[1] += other.y();
    m_e[2] += other.z();

    return *this;
}

vec3 &vec3::operator/=(double p)
{
    m_e[0] *= 1 / p;
    m_e[1] *= 1 / p;
    m_e[2] *= 1 / p;

    return *this;
}

double vec3::length() const
{
    return std::sqrt(squaredLength());
}

double vec3::squaredLength() const
{
    return m_e[0] * m_e[0] + m_e[1] * m_e[1] + m_e[2] * m_e[2];
}