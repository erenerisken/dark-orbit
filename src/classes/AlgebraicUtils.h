//
// Created by Eren Erişken on 3/21/22.
//

#ifndef DARK_ORBIT_ALGEBRAICUTILS_H
#define DARK_ORBIT_ALGEBRAICUTILS_H

#define EPSILON 0.000001

#include <cmath>
#include <numbers>

class AlgebraicUtils {
public:
    static float degreesToRadians(float degrees);
    static float radiansToDegrees(float radians);

    static bool floatEquals(float x, float y);
};


#endif //DARK_ORBIT_ALGEBRAICUTILS_H
