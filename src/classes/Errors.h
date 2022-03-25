//
// Created by Eren Erişken on 3/23/22.
//

#ifndef DARK_ORBIT_ERRORS_H
#define DARK_ORBIT_ERRORS_H

#include <exception>
#include <string>

class ErrorOpeningInputFile: public std::exception {
private:
    std::string reason;
public:
    explicit ErrorOpeningInputFile(const char* underlyingErrorMessage);
    [[nodiscard]] const char * what() const noexcept override;
};

class ErrorReadingInputFile: public std::exception {
private:
    std::string reason;
public:
    explicit ErrorReadingInputFile(const char* underlyingErrorMessage);
    [[nodiscard]] const char * what() const noexcept override;
};

class ErrorReadingInputLine: public std::exception {
private:
    std::string reason;
public:
    explicit ErrorReadingInputLine(const std::string& line);
    [[nodiscard]] const char * what() const noexcept override;
};

#endif //DARK_ORBIT_ERRORS_H
