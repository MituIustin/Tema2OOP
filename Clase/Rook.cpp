#include "Rook.h"
#include "Exception.h"
#include <iostream>

Rook::Rook() : name("rook") {
    std::cout<<"Constructor Rook\n";
    alive = true;
}

Rook *Rook::clone() const {
    std::cout<<"Constructor Clone Rook\n";
    return new Rook(*this);
}


bool Rook::move(int x1, int y1, int x2, int y2) {
    if (x1==x2 && y1==y2) return false;
    bool var = true;
    if(x1 != x2 && y1 != y2) var = false;
    return var;
}

Rook::Rook(const Rook & other) : name(other.name){
    std::cout<<"CC Rook\n";
    alive = other.alive;
}

Rook &Rook::operator=(const Rook & other) {
    std::cout<<"OP= Rook\n";
    alive = other.alive;
    name = other.name;
    return *this;
}

Rook::~Rook() {
    std::cout<<"Destructor Rook\n";
}