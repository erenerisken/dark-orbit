//
// Created by Eren Erişken on 3/25/22.
//

#include "TestRotationMatrix.h"

TestRotationMatrix::TestRotationMatrix(): TestSuite("RotationMatrix") {}

std::vector<test_t> TestRotationMatrix::getUnitTests() {
    std::vector<test_t> tests = {
            {"transpose method", testTranspose},
            {"rotateX method", testRotateX},
            {"aroundAxis method", testAroundAxis},
            {"matrix multiplication", testMatrixMultiplication},
    };
    return tests;
}

bool TestRotationMatrix::testTranspose() {
    Vector3 u(0, 1, 0);
    // this benefits from the fact that transpose of a rotation matrix is equal to its inverse
    // therefore, if we multiply the rotated vector with transpose of rotation matrix,
    // it should get back to its initial position
    auto rotateX = RotationMatrix::rotateX(M_PI_2);
    Vector3 v = rotateX * u;
    Vector3 w = rotateX.transpose() * v;

    return v.equals(Vector3(0, 0, 1)) && u.equals(w);
}

bool TestRotationMatrix::testRotateX() {
    Vector3 u(0, 1, 0);
    auto rotateX = RotationMatrix::rotateX(M_PI_2);
    Vector3 v = rotateX * u;
    Vector3 w = rotateX * v;
    Vector3 p = rotateX * w;
    Vector3 q = rotateX * p;

    return v.equals(Vector3(0, 0, 1)) &&
        w.equals(Vector3(0, -1, 0)) &&
        p.equals(Vector3(0, 0, -1)) &&
        q.equals(u);
}

bool TestRotationMatrix::testAroundAxis() {
    Vector3 u(0, 2, 0);
    auto rotation = RotationMatrix::aroundAxis(Vector3(0, 1, 1), 180);
    Vector3 v = rotation * u;
    return v.equals(Vector3(0, 0, 2));
}

bool TestRotationMatrix::testMatrixMultiplication() {
    Vector3 v(0, 0, 1);
    auto rotateX = RotationMatrix::rotateX(M_PI_2);
    auto reverseRotateX = rotateX.transpose();
    // multiplication with reverse should produce identity, so v should not be transformed
    Vector3 u = rotateX * reverseRotateX * v;
    return v.equals(u);
}

