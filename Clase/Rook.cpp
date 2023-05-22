#include "Rook.h"
#include "Exception.h"
#include <iostream>
#include <memory>

Rook::Rook() {
    std::cout<<"Constructor Rook\n";
    alive = true;
    name = "rook";
}

std::shared_ptr<Piece> Rook::clone() const {
    std::cout << "Constructor Clone Rook\n";
    return std::make_shared<Rook>(*this);
}


bool Rook::move(int x1, int y1, int x2, int y2, bool ok) {
    if (x1==x2 && y1==y2) return false;
    bool var = true;
    if(x1 != x2 && y1 != y2) var = false;
    return var;
}

Rook::~Rook() {
    std::cout<<"Destructor Rook\n";
}