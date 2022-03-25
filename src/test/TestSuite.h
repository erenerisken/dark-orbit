//
// Created by Eren Erişken on 3/25/22.
//

#ifndef DARK_ORBIT_TESTSUITE_H
#define DARK_ORBIT_TESTSUITE_H

#include <string>
#include <vector>

typedef std::pair<std::string, bool(*)()> test_t;

class TestSuite {
private:
    std::string name;

public:
    explicit TestSuite(std::string  name);
    virtual std::vector<test_t> getUnitTests() = 0;
    [[nodiscard]] const std::string& getName() const;

    virtual ~TestSuite() = default;
};


#endif //DARK_ORBIT_TESTSUITE_H
