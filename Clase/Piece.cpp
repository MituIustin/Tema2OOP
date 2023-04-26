#include "Piece.h"
#include <iostream>
Piece::Piece() {
    std::cout<<"\nConstructor Piece\n";
    alive = true;
}

void Piece::move() {

}

Piece::~Piece() {
    std::cout<<"Destructor Piece\n";
}
//CLASA ABSTRACTA