//
// Created by Eren Erişken on 3/25/22.
//

#ifndef DARK_ORBIT_TESTROTATIONMATRIX_H
#define DARK_ORBIT_TESTROTATIONMATRIX_H

#define _USE_MATH_DEFINES

#include <cmath>

#include "../classes/RotationMatrix.h"
#include "TestSuite.h"

class TestRotationMatrix : public TestSuite{
private:
    static bool testTranspose();
    static bool testRotateX();
    static bool testAroundAxis();
    static bool testMatrixMultiplication();
    // since we already tested multiplication with a vector, no need to duplicate it so passing
public:
    TestRotationMatrix();
    std::vector<test_t> getUnitTests() override;
};


#endif //DARK_ORBIT_TESTROTATIONMATRIX_H
