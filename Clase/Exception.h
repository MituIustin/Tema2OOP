#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception {
public:
    Exception(const std::string& message);

    virtual const char* what() const noexcept override;

private:
    std::string message_;
};

class NoTexture : public Exception {
public:
    NoTexture() : Exception("The texture could not be loaded. \n") {}
};

class NotValidMove : public Exception {
public:
    NotValidMove() : Exception("This is not a valid move in Chess. \n") {}
};

class NotValidXY : public Exception {
public:
    NotValidXY() : Exception("Wrong coordinates. \n") {}
};

class WindowNotOpened : public Exception {
public:
    WindowNotOpened() : Exception("The window could not be opened. \n") {}
};

class ClassNotUsed : public Exception {
public:
    ClassNotUsed() : Exception("This class is never used ") {}
};

#endif  // EXCEPTION_H