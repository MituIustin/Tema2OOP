#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception {
public:
    explicit Exception(const std::string& message);
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

class NoPieces : public Exception {
public:
    NoPieces() : Exception("There is no piece created / All pieces have been deleted . \n") {}
};

class NotValidPosition : public Exception {
public:
    NotValidPosition() : Exception("The position of the chess piece is not valid \n") {}
};


#endif  // EXCEPTION_H