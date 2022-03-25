//
// Created by Eren Erişken on 3/25/22.
//
#include <exception>
#include <iostream>

#include "TestSuite.h"
#include "TestVector3.h"
#include "TestRotationMatrix.h"
#include "TestSphere.h"

void printLinePrefix(int success, int fail, bool indent = false) {
    std::cout << (indent ? "\t" : "") << "+" << success << " -" << fail << " ";
}

int main() {
    std::cout << "Running tests..." << std::endl;

    std::vector<TestSuite*> suites {new TestVector3(), new TestSphere(), new TestRotationMatrix()};
    size_t numSuites = suites.size();

    int success = 0;
    int fail = 0;
    for (auto *suite: suites) {
        printLinePrefix(success, fail);
        std::cout << "[SUITE] " << suite->getName() << std::endl;
        auto testCases = suite->getUnitTests();
        for (auto &testCase: testCases) {
            printLinePrefix(success, fail, true);
            std::cout << "[RUNNING] " << testCase.first << std::endl;
            bool result;
            try {
                result = (*testCase.second)();
            } catch (std::exception& e) {
                printLinePrefix(success, ++fail, true);
                std::cout << "[EXCEPTION] " << testCase.first << ": " << e.what() << std::endl;
                continue;
            }
            if (result) {
                printLinePrefix(++success, fail, true);
                std::cout << "[SUCCESS] " << testCase.first << std::endl;
            } else {
                printLinePrefix(success, ++fail, true);
                std::cout << "[FAIL] " << testCase.first << std::endl;
            }
        }
    }

    std::cout << "----------------------------------" << std::endl << std::endl;

    if (fail == 0) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << success << "/" << (success + fail) << " tests passed!" << std::endl;
    }

    for (size_t i = 0; i < numSuites; ++i) {
        delete suites[i];
    }
    return 0;
}