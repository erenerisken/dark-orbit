//
// Created by Eren Erişken on 3/23/22.
//

#include "Errors.h"

ErrorOpeningInputFile::ErrorOpeningInputFile(const char *underlyingErrorMessage) {
    reason = std::string("Error occurred while opening the input file: ") + std::string(underlyingErrorMessage);
}

const char *ErrorOpeningInputFile::what() const noexcept {
    return reason.c_str();
}

ErrorReadingInputFile::ErrorReadingInputFile(const char *underlyingErrorMessage) {
    reason = std::string("Error occurred while reading the input file: ") +
            std::string(underlyingErrorMessage);
}

const char *ErrorReadingInputFile::what() const noexcept {
    return reason.c_str();
}

ErrorReadingInputLine::ErrorReadingInputLine(const std::string &line) {
    reason = std::string("Could not read line: ") + line;
}

const char *ErrorReadingInputLine::what() const noexcept {
    return reason.c_str();
}
