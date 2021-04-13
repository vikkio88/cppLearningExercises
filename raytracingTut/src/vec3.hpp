#pragma once

#include <cmath>
#include <iostream>

class vec3
{
private:
    double m_e[3];

public:
    vec3() : m_e{0, 0, 0} {}
    vec3(double x, double y, double z) : m_e{x, y, z} {}

    double x() const { return m_e[0]; }
    double y() const { return m_e[1]; }
    double z() const { return m_e[2]; }

    vec3 operator-() const;
    double operator[](int i) const;
    double &operator[](int i);

    vec3 &operator+(const vec3 &other);
    vec3 &operator/=(double p);

    double length() const;
    double squaredLength() const;
};

// Type aliases for vec3
using point3 = vec3; // 3D point
using colour = vec3; // RGB colour

//Utils
inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline vec3 operator*(double t, const vec3 &v)
{
    return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3 &v, double t)
{
    return t * v;
}

inline vec3 operator/(vec3 v, double t)
{
    return (1 / t) * v;
}

inline double dot(const vec3 &u, const vec3 &v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

inline vec3 unit_vector(vec3 v)
{
    return v / v.length();
}