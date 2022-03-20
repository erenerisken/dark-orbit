//
// Created by Eren Erişken on 3/21/22.
//
#include <iostream>

#include "../classes/RotationMatrix.h"

bool simpleRotation() {
    Vector3 p(3, 0, 0);
    Vector3 axis(1, 0, 1);
    RotationMatrix rotationMatrix = RotationMatrix::aroundAxis(axis, 90);
    Vector3 result = rotationMatrix * p;
    std::cout << "Result: " << result << std::endl;

    return true;
}

int main() {
    simpleRotation();

    return 0;
}