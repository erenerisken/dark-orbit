//
// Created by Eren Erişken on 3/25/22.
//

#ifndef DARK_ORBIT_TESTSPHERE_H
#define DARK_ORBIT_TESTSPHERE_H

#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>

#include "../classes/Utilities.h"
#include "../classes/Sphere.h"

#include "TestSuite.h"

class TestSphere: public TestSuite{
private:
    static bool testGetAxis();
    static bool testGetPositions();
    static bool testClosestDistanceToCollision();
    static bool testClosestDistanceToSameOmega();
    static bool testRadialDistanceTo();
    static bool testComparisonOperator();
    static bool testSorting();
public:
    TestSphere();
    std::vector<test_t> getUnitTests() override;
};


#endif //DARK_ORBIT_TESTSPHERE_H
