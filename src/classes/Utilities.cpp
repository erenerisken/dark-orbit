//
// Created by Eren Erişken on 3/21/22.
//

#include "Utilities.h"

float Utilities::degreesToRadians(float degrees) {
    return degrees * std::numbers::pi_v<float> / 180;
}

float Utilities::radiansToDegrees(float radians) {
    return radians * 180 / std::numbers::pi_v<float>;
}

bool Utilities::floatEquals(float x, float y) {
    return std::abs(x - y) < EPSILON;
}

void Utilities::setNumIntervals(size_t n) {
    numIntervals = n;
}

size_t Utilities::getNumIntervals() const {
    return numIntervals;
}

size_t Utilities::atou(const char *s) {
    std::istringstream reader(s);
    size_t value;
    reader >> value;
    return value;
}
