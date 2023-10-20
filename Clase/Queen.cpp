#include "Queen.h"
#include "Exception.h"

#include <iostream>
#include <memory>

Queen::Queen() {
    std::cout << "Constructor Queen\n";
    alive = true;
    name = "queen";
}

std::shared_ptr < Piece > Queen::clone() const {
    std::cout << "Constructor Clone Queen\n";
    return std::make_shared < Queen > (Queen( * this));
}

bool Queen::move(int x1, int y1, int x2, int y2, bool ok) {
    if (x1 == x2 && y1 == y2) return false;
    if (abs(x1 - x2) == abs(y1 - y2) || abs(x1 - y1) == abs(x2 - y2)) return true;
    bool
    var = true;
    if (x1 != x2 && y1 != y2) var = false;
    return var;
}

Queen::~Queen() {
    std::cout << "Destructor Queen\n";
}
