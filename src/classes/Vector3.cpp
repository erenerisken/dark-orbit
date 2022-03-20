//
// Created by Eren Erişken on 3/20/22.
//

#include <cmath>

#include "Vector3.h"

Vector3::Vector3(): x(0), y(0), z(0) {}
Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {}

float Vector3::getX() const {
    return x;
}

void Vector3::setX(float x) {
    Vector3::x = x;
}

float Vector3::getY() const {
    return y;
}

void Vector3::setY(float y) {
    Vector3::y = y;
}

float Vector3::getZ() const {
    return z;
}

void Vector3::setZ(float z) {
    Vector3::z = z;
}

Vector3 Vector3::fromSphericalCoordinates(float theta, float phi, float r) {
    float sinPhi = std::sin(phi);

    float z = r * std::cos(phi);
    float y = r * std::sin(theta) * sinPhi;
    float x = r * std::cos(theta) * sinPhi;

    return {x, y, z};
}

Vector3 Vector3::operator*(const Vector3& rhs) const {
    float newX = y * rhs.z - z * rhs.y;
    float newY = z * rhs.x - x * rhs.z;
    float newZ = x * rhs.y - y * rhs.x;

    return {newX, newY, newZ};
}

float Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalized() const {
    float magnitude = length();

    return magnitude > 0 ?
        Vector3(x / magnitude, y / magnitude, z / magnitude) :
        Vector3(0, 0, 0);
}

bool Vector3::equals(const Vector3 &rhs) const {
    return AlgebraicUtils::floatEquals(x, rhs.x) &&
            AlgebraicUtils::floatEquals(y, rhs.y) &&
            AlgebraicUtils::floatEquals(z, rhs.z);
}

std::ostream &operator<<(std::ostream &o, const Vector3 &v) {
    o << "X=" << v.x << " Y=" << v.y << " Z=" << v.z;
    return o;
}
