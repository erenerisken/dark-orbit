//
// Created by Eren Erişken on 3/25/22.
//

#include "TestVector3.h"

TestVector3::TestVector3() : TestSuite("Vector3") {}

bool TestVector3::testLength() {
    Vector3 v(4, 8, 1);

    return Utilities::floatEquals(9, v.length());
}

bool TestVector3::testNormalized() {
    Vector3 v(4, 8, 1);

    return v.normalized().equals(Vector3(4.0 / 9, 8.0 / 9, 1.0 / 9));
}

std::vector<test_t> TestVector3::getUnitTests() {
    std::vector<test_t> tests = {
            {"length method", testLength},
            {"normalized method", testNormalized},
            {"distanceTo method", testDistanceTo},
            {"equals method gives true for equal vectors", testEqualsToTrue},
            {"equals method gives false for unequal vectors", testEqualsToFalse},
            {"fromSphericalCoordinates method", testFromSphericalCoordinates},
            {"cross product with another vector", testCrossProduct},
    };

    return tests;
}

bool TestVector3::testDistanceTo() {
    Vector3 v(4, 8, 1);
    Vector3 u(8, 16, 2);

    return Utilities::floatEquals(v.distanceTo(u), 9);
}

bool TestVector3::testEqualsToTrue() {
    Vector3 v(4, 8, 1);

    return v.equals(Vector3(4, 8, 1));
}

bool TestVector3::testEqualsToFalse() {
    Vector3 v(4, 9, 1);

    return !v.equals(Vector3(4, 8, 1));
}

bool TestVector3::testFromSphericalCoordinates() {
    auto v = Vector3::fromSphericalCoordinates(M_PI_2, M_PI_2, 4);

    return v.equals(Vector3(0, 4, 0));
}

bool TestVector3::testCrossProduct() {
    Vector3 u(1, 4, 1);
    Vector3 v(3, 5, 2);

    return (u * v).equals(Vector3(3, 1, -7));
}
