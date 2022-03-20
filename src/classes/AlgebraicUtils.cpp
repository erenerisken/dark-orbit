//
// Created by Eren Erişken on 3/21/22.
//

#include "AlgebraicUtils.h"

float AlgebraicUtils::degreesToRadians(float degrees) {
    return degrees * std::numbers::pi_v<float> / 180;
}

float AlgebraicUtils::radiansToDegrees(float radians) {
    return radians * 180 / std::numbers::pi_v<float>;
}

bool AlgebraicUtils::floatEquals(float x, float y) {
    return std::abs(x - y) < EPSILON;
}
