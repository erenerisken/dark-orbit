//
// Created by Eren Erişken on 3/20/22.
//

#ifndef DARK_ORBIT_VECTOR3_H
#define DARK_ORBIT_VECTOR3_H

#include <iostream>
#include "AlgebraicUtils.h"

class Vector3 {
private:
    float x,y,z;
public:
    Vector3();
    Vector3(float x, float y, float z);

    [[nodiscard]] float getX() const;
    void setX(float x);

    [[nodiscard]] float getY() const;
    void setY(float y);

    [[nodiscard]] float getZ() const;
    void setZ(float z);

    [[nodiscard]] float length() const;
    [[nodiscard]] Vector3 normalized() const;

    [[nodiscard]] bool equals(const Vector3& rhs) const;

    static Vector3 fromSphericalCoordinates(float theta, float phi, float r);

    Vector3 operator*(const Vector3& rhs) const;
    friend std::ostream& operator<<(std::ostream& o, const Vector3& v);
};


#endif //DARK_ORBIT_VECTOR3_H
