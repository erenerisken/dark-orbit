//
// Created by Eren Erişken on 3/21/22.
//

#ifndef DARK_ORBIT_UTILITIES_H
#define DARK_ORBIT_UTILITIES_H

#include <cmath>
#include <numbers>

#define EPSILON 0.000001

class Utilities {
private:
    size_t numIntervals = 1;
public:
    void setNumIntervals(size_t n);
    [[nodiscard]] size_t getNumIntervals() const;

    static float degreesToRadians(float degrees);
    static float radiansToDegrees(float radians);

    static bool floatEquals(float x, float y);
};


#endif //DARK_ORBIT_UTILITIES_H
