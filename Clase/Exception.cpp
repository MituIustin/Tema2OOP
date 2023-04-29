#include "Exception.h"
#include <iostream>

Exception::Exception(const std::string& message) : message_(message) {
    std::cout<<"Constructor Exceptie\n";
}

const char* Exception::what() const noexcept {
    return message_.c_str();
}