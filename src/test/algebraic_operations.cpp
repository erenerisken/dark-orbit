//
// Created by Eren Erişken on 3/21/22.
//
#include <iostream>

#include "../classes/RotationMatrix.h"
#include "../classes/Sphere.h"

bool simpleRotation() {
    Vector3 p(3, 0, 0);
    Vector3 axis(1, 0, 1);
    RotationMatrix rotationMatrix = RotationMatrix::aroundAxis(axis, 90);
    Vector3 result = rotationMatrix * p;
    std::cout << "Result: " << result << std::endl;

    return true;
}

bool sphereAxis() {
    Sphere sphere(3, 0, 1.57, 180, {0, 0, -1});
    std::cout << "Axis of sphere: " << sphere.getAxis() << std::endl;

    return true;
}

int main() {
    simpleRotation();
    sphereAxis();

    return 0;
}