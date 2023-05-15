#include "Pawn.h"
#include <iostream>
#include <cmath>
#include <memory>

Pawn::Pawn() : name("pawn"){
    std::cout<<"Constructor Pawn\n";
    alive = true;
}

std::shared_ptr<Piece> Pawn::clone() const {
    std::cout<<"Constructor Clone Pawn\n";
    return std::make_shared<Pawn>( Pawn(*this) );
}

bool Pawn::move(int x1, int x2, int y1, int y2) {
    if (x1==y1 && x2==y2) return false;
    if(x2==y2 && abs(x1-y1)<=2) return true;
    return false;
}

Pawn::Pawn(const Pawn & other) : name(other.name) {
    std::cout<<"CC Pawn\n";
    alive = other.alive;
}

Pawn &Pawn::operator=(const Pawn & other) {
    std::cout<<"OP= Pawn\n";
    alive = other.alive;
    name = other.name;
    return *this;
}

Pawn::~Pawn() {
    std::cout<<"Destructor Pawn\n";
}