//
// Created by Eren Erişken on 3/21/22.
//

#ifndef DARK_ORBIT_UTILITIES_H
#define DARK_ORBIT_UTILITIES_H

#include <cmath>
#include <numbers>
#include <sstream>

/**
 * Degree of tolerance for comparing two 32 bit float values
 */
#define EPSILON 0.0001
/**
 * Minimum number of spheres per thread
 */
#define SPHERES_PER_THREAD 36

/**
 * Class for holding miscellaneous variables and helper functions
 */
class Utilities {
private:
    /**
     * number of steps for 1 unit time
     * for example, if numIntervals is 5, step size of the simulation is 0.2
     */
    size_t numIntervals = 1;
public:
    void setNumIntervals(size_t n);
    [[nodiscard]] size_t getNumIntervals() const;

    /**
     * Converts degrees to radians
     * @param degrees angle to be converted in degrees
     * @return converted angle in radians
     */
    static float degreesToRadians(float degrees);

    /**
     * Converts radians to degrees
     * @param radians angle to be converted in radians
     * @return converted angle in degrees
     */
    static float radiansToDegrees(float radians);

    /**
     * equality comparison for two floats with EPSILON tolerance
     * i.e. |x-y| < EPSILON
     * @param x first float value to be compared
     * @param y second float value to be compared
     * @return true if the two values are as close as EPSILON, false otherwise
     */
    static bool floatEquals(float x, float y);

    /**
     * Converts a string given as char array to a 64 bit unsigned integer
     * @param s null terminated char array to be converted to u64
     * @return u64 representation of the given char array
     */
    static size_t atou(const char* s);
};


#endif //DARK_ORBIT_UTILITIES_H
