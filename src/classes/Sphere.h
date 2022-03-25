//
// Created by Eren Erişken on 3/21/22.
//

#ifndef DARK_ORBIT_SPHERE_H
#define DARK_ORBIT_SPHERE_H

#include <vector>

#include "RotationMatrix.h"

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

    void initializePositions();
public:
    Sphere(int index, Utilities& utilities, unsigned int radius, float theta, float phi, int w, const Vector3 &uv);

    Sphere& operator=(const Sphere& rhs);

    [[nodiscard]] const Vector3 &getAxis() const;

    [[nodiscard]] int getIndex() const;

    const std::vector<Vector3> &getPositions();

    std::pair<float, float> closestDistanceTo(Sphere& rhs);
    [[nodiscard]] float radialDistanceTo(const Sphere& rhs) const;

    friend bool operator<(const Sphere& lhs, const Sphere& rhs);
};


#endif //DARK_ORBIT_SPHERE_H
