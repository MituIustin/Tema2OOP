#include "Bishop.h"
#include <iostream>
#include <cmath>
#include "Exception.h"

Bishop::Bishop() : name("bishop"){
    std::cout<<"Constructor Bishop\n";
    alive = true;
}

Bishop *Bishop::clone() const {
    std::cout<<"Constructor Clone Bishop\n";
    return new Bishop(*this);
}

Bishop::Bishop(const Bishop & other) : name(other.name) {
    std::cout<<"CC Bishop\n";
    alive = other.alive;
}

Bishop &Bishop::operator=(const Bishop & other) {
    std::cout<<"OP= Bishop";
    name = other.name;
    return *this;
}

bool Bishop::move(int x1, int y1, int x2, int y2) {
    if(abs(x1-x2) == abs(y1-y2) || abs(x1-y1) == abs(x2-y2)) return true;
    return false;
}

Bishop::~Bishop() {
    std::cout<<"Destructor Bishop\n";
}