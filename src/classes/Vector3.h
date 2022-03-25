//
// Created by Eren Erişken on 3/20/22.
//

#ifndef DARK_ORBIT_VECTOR3_H
#define DARK_ORBIT_VECTOR3_H

#include <iostream>
#include "Utilities.h"

/**
 * 3D vector containing 3 float values x, y and z
 */
class Vector3 {
private:
    float x,y,z;
public:
    /**
     * Initializes a zero vector
     */
    Vector3();
    /**
     * Initializes a vector with given x, y, z values
     * @param x i component of the vector
     * @param y j component of the vector
     * @param z k component of the vector
     */
    Vector3(float x, float y, float z);

    [[nodiscard]] float getX() const;
    void setX(float x);

    [[nodiscard]] float getY() const;
    void setY(float y);

    [[nodiscard]] float getZ() const;
    void setZ(float z);

    /**
     * Calculates and returns magnitude of the vector
     * @return Magnitude of the vector
     */
    [[nodiscard]] float length() const;
    /**
     * Calculates and returns a vector with the same direction as itself and a length of 1
     * @return normalized version of the vector (|u| = 1)
     */
    [[nodiscard]] Vector3 normalized() const;

    /**
     * Calculates and returns the distance to given vector
     * @param rhs second vector to calculate the distance
     * @return |this - rhs|
     */
    [[nodiscard]] float distanceTo(const Vector3& rhs) const;
    /**
     * Checks whether both vectors are identical
     * @param rhs right hand side of the comparison
     * @return true if both are equal, false otherwise
     */
    [[nodiscard]] bool equals(const Vector3& rhs) const;

    /**
     * Generates and returns a vector from given spherical coordinates
     * @param theta azimuth (angle with x-axis) in radians
     * @param phi inclination (angle with z-axis) in radians
     * @param r radius component (distance from origin)
     * @return generated vector from given spherical coordinates
     */
    static Vector3 fromSphericalCoordinates(float theta, float phi, float r);

    /**
     * Calculates the cross product of the vector with given vector and returns the resulting vector
     * @param rhs right hand side of the cross product
     * @return this x rhs
     */
    Vector3 operator*(const Vector3& rhs) const;
    /**
     * outputs given vector as 'X=<x> Y=<y> Z=<z>' to the given output stream
     * @param o output stream to print
     * @param v vector to be printed
     * @return o for cascading
     */
    friend std::ostream& operator<<(std::ostream& o, const Vector3& v);
};


#endif //DARK_ORBIT_VECTOR3_H
