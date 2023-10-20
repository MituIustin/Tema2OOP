#include "Bishop.h"

#include <iostream>
#include <cmath>
#include <memory>

Bishop::Bishop() {
   std::cout << "Constructor Bishop\n";
   alive = true;
   name = "bishop";
}

std::shared_ptr < Piece > Bishop::clone() const {
   std::cout << "Constructor Clone Bishop\n";
   return std::make_shared < Bishop > (Bishop( * this));
}

bool Bishop::move(int x1, int y1, int x2, int y2, bool ok) {
   if (x1 == x2 && y1 == y2) return false;
   if (abs(x1 - x2) == abs(y1 - y2) || abs(x1 - y1) == abs(x2 - y2)) return true;
   return false;
}

Bishop::~Bishop() {
   std::cout << "Destructor Bishop\n";
}
