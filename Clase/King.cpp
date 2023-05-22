#include "King.h"
#include "Exception.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
King::King() {
    std::cout<<"Constructor King\n";
    alive = true;
    name = "king";
}

std::shared_ptr<Piece> King::clone() const {
    std::cout<<"Constructor Clone King\n";
    return std::make_shared<King>(King(*this));
}

bool King::move(int x1, int y1, int x2, int y2, bool ok) {
    if (x1==x2 && y1==y2) return false;
    if(abs(x1-x2)<=1 && abs(y1-y2)<=1) return true;
    return false;
}


King::~King() {
    std::cout<<"Destructor King\n";
}