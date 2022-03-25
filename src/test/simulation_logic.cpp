//
// Created by Eren Erişken on 3/21/22.
//

#include <iostream>
#include "../classes/Sphere.h"

Utilities utilities;

bool spherePositionsCalculation() {
    Sphere sphere(utilities, 1, 1.57, 1.57, 45, {0, 0, 1});

    auto &positions = sphere.getPositions();

    std::cout << "-----------------Positions of the sphere---------------------" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << (i + 1) << ": " << positions[i] << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;

    return true;
}

bool sphereDistances() {
    Sphere sphere1(1, utilities, 1, 1.57, 1.57, 45, {0, 0, 1});
    Sphere sphere2(2, utilities, 3, 1.57, 0, 90, {1, 0, 0});

    std::cout << "Distance between spheres: " << sphere1.closestDistanceTo(sphere2) << std::endl;
    return true;
}

int main() {
    utilities.setNumIntervals(1);

    spherePositionsCalculation();
    sphereDistances();

    return 0;
}