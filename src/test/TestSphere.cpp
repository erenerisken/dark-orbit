//
// Created by Eren Erişken on 3/25/22.
//

#include "TestSphere.h"

TestSphere::TestSphere() : TestSuite("Sphere") {}

bool TestSphere::testGetAxis() {
    Utilities utilities;
    Sphere sphere(1, utilities, 3, M_PI_2, M_PI_2, 60, {1, 0, 0});
    return sphere.getAxis().equals(Vector3(0, 0, -1));
}

std::vector<test_t> TestSphere::getUnitTests() {
    std::vector<test_t> tests = {
            {"getAxis method", testGetAxis},
            {"getPositions method", testGetPositions},
            {"closestDistanceTo gives distance = 0 and finds first time for colliding spheres", testClosestDistanceToCollision},
            {"closestDistanceTo gives sum of radius for spheres rotating with same w starting from opposite positions", testClosestDistanceToSameOmega},
            {"radialDistanceTo method", testRadialDistanceTo},
            {"comparison operator", testComparisonOperator},
            {"sorting of spheres", testSorting},
    };

    return tests;
}

bool TestSphere::testGetPositions() {
    Utilities utilities;
    Sphere sphere(1, utilities, 3, M_PI_2, M_PI_2, 30, {1, 0, 0});
    auto &positions = sphere.getPositions();

    return positions[0].equals(Vector3(0, 3, 0)) &&
        positions[3].equals(Vector3(3, 0, 0)) &&
        positions[6].equals(Vector3(0, -3, 0)) &&
        positions[9].equals(Vector3(-3, 0, 0)) &&
        positions[12].equals(positions[0]);
}

bool TestSphere::testClosestDistanceToCollision() {
    Utilities utilities;
    Sphere sphere1(1, utilities, 3, M_PI_2, M_PI_2, 30, {1, 0, 0});
    Sphere sphere2(2, utilities, 3, -M_PI_2, M_PI_2, 30, {1, 0, 0});

    auto result = sphere1.closestDistanceTo(sphere2);
    return Utilities::floatEquals(result.first, 0) && Utilities::floatEquals(result.second, 3);
}

bool TestSphere::testClosestDistanceToSameOmega() {
    Utilities utilities;
    Sphere sphere1(1, utilities, 3, M_PI_2, M_PI_2, 30, {1, 0, 0});
    Sphere sphere2(2, utilities, 3, -M_PI_2, M_PI_2, 30, {-1, 0, 0});

    auto result = sphere1.closestDistanceTo(sphere2);
    return Utilities::floatEquals(result.first, 6) && Utilities::floatEquals(result.second, 0);
}

bool TestSphere::testRadialDistanceTo() {
    Utilities utilities;
    Sphere sphere1(1, utilities, 3, M_PI_2, M_PI_2, 30, {1, 0, 0});
    Sphere sphere2(2, utilities, 14, -M_PI_2, M_PI_2, 30, {-1, 0, 0});

    return Utilities::floatEquals(sphere1.radialDistanceTo(sphere2), 11);
}

bool TestSphere::testComparisonOperator() {
    Utilities utilities;
    Sphere sphere1(1, utilities, 3, M_PI_2, M_PI_2, 30, {1, 0, 0});
    Sphere sphere2(2, utilities, 14, -M_PI_2, M_PI_2, 30, {-1, 0, 0});

    return (sphere1 < sphere2) && !(sphere2 < sphere1);
}

bool TestSphere::testSorting() {
    Utilities utilities;
    Sphere sphere1(1, utilities, 30, M_PI_2, M_PI_2, 30, {1, 0, 0});
    Sphere sphere2(2, utilities, 14, -M_PI_2, M_PI_2, 30, {-1, 0, 0});
    Sphere sphere3(3, utilities, 1, -M_PI_2, M_PI_2, 30, {-1, 0, 0});
    std::vector<Sphere> spheres{sphere1, sphere2, sphere3};
    std::sort(spheres.begin(), spheres.end());

    return spheres[0].getIndex() == 3 && spheres[1].getIndex() == 2 && spheres[2].getIndex() == 1;
}
