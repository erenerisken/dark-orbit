//
// Created by Eren Erişken on 3/25/22.
//

#include "TestSuite.h"

#include <utility>

TestSuite::TestSuite(std::string name): name(std::move(name)) {}

const std::string &TestSuite::getName() const {
    return name;
}
