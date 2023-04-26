#include "Pawn.h"

#include <iostream>

Pawn::Pawn() {
    std::cout<<"Constructor Pawn\n";
    alive = true;
}

void Pawn::move() {

}

Pawn::~Pawn() {
    std::cout<<"Destructor Pawn\n";
}