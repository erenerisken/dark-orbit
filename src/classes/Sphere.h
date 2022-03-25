//
// Created by Eren Erişken on 3/21/22.
//

#ifndef DARK_ORBIT_SPHERE_H
#define DARK_ORBIT_SPHERE_H

#include <vector>

#include "RotationMatrix.h"

/**
 * Class for wrapping observed sphere data
 */
class Sphere {
private:
    Utilities& utilities;
    int index;

    unsigned int radius;
    float theta;
    float phi;
    int w;
    Vector3 uv;
    Vector3 cartesianCoordinates;
    Vector3 axis;

    std::vector<Vector3> positions;

    std::vector<Vector3> initializePositions(size_t t = 360);
public:
    /**
     * Initializes a new Sphere
     * @param index Index of the sphere (starting from 1) corresponds to number of line in input file containing it
     * @param utilities Reference to the global utilities class initialized in main program
     * @param radius radius of the sphere
     * @param theta azimuth (angle with x-axis) in radians of the position of the sphere with respect to origin
     * @param phi inclination (angle with z-axis) in radians of the position of the sphere with respect to origin
     * @param w angular velocity in degrees per unit time
     * @param uv direction vector of initial motion as unit vector
     */
    Sphere(int index, Utilities& utilities, unsigned int radius, float theta, float phi, int w, const Vector3 &uv);

    Sphere& operator=(const Sphere& rhs);

    [[nodiscard]] const Vector3 &getAxis() const;

    [[nodiscard]] int getIndex() const;

    /**
     * Calculates the motion of the sphere in first 360 unit time, stores them in 'positions' vector
     * step size depends on numIntervals variable defined in given Utilities instance
     * @return reference to positions vector after the calculation
     */
    const std::vector<Vector3> &getPositions();

    /**
     * calculates the closest approximation of this sphere and the given sphere in any time t
     * @param rhs the sphere to calculate approximation with current sphere
     * @return closest distance and corresponding time, respectively
     */
    std::pair<float, float> closestDistanceTo(Sphere& rhs);
    /**
     * calculates the radial distance between two spheres (difference of orbital radius of the spheres)
     * @param rhs the sphere to calculate radial distance with current sphere
     * @return radial distance |r_this - r_rhs|
     */
    [[nodiscard]] float radialDistanceTo(const Sphere& rhs) const;

    /**
     * override of comparison operator for sorting the spheres according to their radius
     * @param lhs left hand side of the comparison
     * @param rhs right hand side of the comparison
     * @return true if lhs.radius < rhs.radius, false otherwise
     */
    friend bool operator<(const Sphere& lhs, const Sphere& rhs);
};


#endif //DARK_ORBIT_SPHERE_H
