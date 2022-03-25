//
// Created by Eren Erişken on 3/25/22.
//

#ifndef DARK_ORBIT_TESTVECTOR3_H
#define DARK_ORBIT_TESTVECTOR3_H

#define _USE_MATH_DEFINES

#include <cmath>

#include "../classes/Vector3.h"
#include "../classes/Utilities.h"
#include "TestSuite.h"

class TestVector3 : public TestSuite{
private:
    static bool testLength();
    static bool testNormalized();
    static bool testDistanceTo();
    static bool testEqualsToTrue();
    static bool testEqualsToFalse();
    static bool testFromSphericalCoordinates();
    static bool testCrossProduct();

public:
    TestVector3();
    std::vector<test_t> getUnitTests() override;
};


#endif //DARK_ORBIT_TESTVECTOR3_H
