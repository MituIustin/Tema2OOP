#include "King.h"
#include "Exception.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
King::King() : name("king"){
    std::cout<<"Constructor King\n";
    alive = true;
}

King *King::clone() const {
    std::cout<<"Constructor Clone King\n";
    return new King(*this);
}

King::King(const King &other) : name(other.name) {
    std::cout<<"CC King\n";
    alive = other.alive;
};

King &King::operator=(const King & other) {
    std::cout<<"OP= King\n";
    alive = other.alive;
    return *this;
}

bool King::move(int x1, int y1, int x2, int y2) {
    if (x1==x2 && y1==y2) return false;
    if(abs(x1-x2)<=1 && abs(y1-y2)<=1) return true;
    return false;
}


King::~King() {
    std::cout<<"Destructor King\n";
}