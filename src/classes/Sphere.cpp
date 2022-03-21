//
// Created by Eren Erişken on 3/21/22.
//

#include "Sphere.h"

Sphere::Sphere(int index, const Utilities& utilities, unsigned int radius, float theta, float phi, int w, const Vector3 &uv):
    index(index), utilities(utilities), radius(radius), theta(theta), phi(phi), w(w), uv(uv) {

    cartesianCoordinates = Vector3::fromSphericalCoordinates(theta, phi, (float)radius);
    axis = (cartesianCoordinates * uv).normalized();
}

const Vector3 &Sphere::getAxis() const {
    return axis;
}

const std::vector<Vector3> &Sphere::getPositions() {
    if (positions.empty()) {
        initializePositions();
    }

    return positions;
}

void Sphere::initializePositions() {
    size_t numIntervals = utilities.getNumIntervals();
    size_t numPositions = 360 * numIntervals;
    float degreesPerUnitTime = (float)w / (float)numIntervals;
    RotationMatrix rotationMatrix = RotationMatrix::aroundAxis(axis, degreesPerUnitTime);

    positions.resize(numPositions);
    positions[0] = cartesianCoordinates;
    for (size_t i = 1; i < numPositions; ++i) {
        positions[i] = rotationMatrix * positions[i - 1];
    }
}

float Sphere::closestDistanceTo(Sphere &rhs) {
    auto &selfPositions = getPositions();
    auto &rhsPositions = rhs.getPositions();
    size_t numPositions = selfPositions.size();

    float minDistance = selfPositions[0].distanceTo(rhsPositions[0]);
    for (size_t i = 1; i < numPositions; ++i) {
        minDistance = std::min(minDistance, selfPositions[i].distanceTo(rhsPositions[i]));
    }

    return minDistance;
}

unsigned int Sphere::radialDistanceTo(const Sphere &rhs) const {
    return std::abs((int)radius - (int)rhs.radius);
}

int Sphere::getIndex() const {
    return index;
}

bool operator<(const Sphere &lhs, const Sphere &rhs) {
    return lhs.radius < rhs.radius;
}
