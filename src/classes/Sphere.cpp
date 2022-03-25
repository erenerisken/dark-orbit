//
// Created by Eren Erişken on 3/21/22.
//

#include "Sphere.h"

Sphere::Sphere(int index, Utilities& utilities, unsigned int radius, float theta, float phi, int w, const Vector3 &uv):
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
    std::vector<Vector3> calculatedPositions;
    calculatedPositions.resize(numPositions);
    calculatedPositions[0] = cartesianCoordinates;
    for (size_t i = 1; i < numPositions; ++i) {
        calculatedPositions[i] = rotationMatrix * calculatedPositions[i - 1];
    }
    positions = calculatedPositions;
}

std::pair<float, float> Sphere::closestDistanceTo(Sphere &rhs) {
    auto &selfPositions = getPositions();
    auto &rhsPositions = rhs.getPositions();
    size_t numPositions = selfPositions.size();

    float minDistance = selfPositions[0].distanceTo(rhsPositions[0]);
    float t = 0;
    for (size_t i = 1; i < numPositions; ++i) {
        float distanceAtT = selfPositions[i].distanceTo(rhsPositions[i]);
        if (distanceAtT < (minDistance - EPSILON)) {
            minDistance = distanceAtT;
            t = (float)i / (float)utilities.getNumIntervals();
        }
    }

    return {minDistance, t};
}

float Sphere::radialDistanceTo(const Sphere &rhs) const {
    return std::fabs((float)radius - (float)rhs.radius);
}

int Sphere::getIndex() const {
    return index;
}

bool operator<(const Sphere &lhs, const Sphere &rhs) {
    return lhs.radius < rhs.radius;
}

Sphere &Sphere::operator=(const Sphere &rhs) {
    index = rhs.index;
    utilities = rhs.utilities;
    radius = rhs.radius;
    theta = rhs.theta;
    phi = rhs.phi;
    w = rhs.w;
    uv = rhs.uv;
    cartesianCoordinates = rhs.cartesianCoordinates;
    axis = rhs.axis;
    positions = rhs.positions;

    return *this;
}
