#include "Knight.h"
#include <iostream>
#include <memory>

Knight::Knight(){
    std::cout<<"Constructor Knight\n";
    alive = true;
    name = "knight";
}

std::shared_ptr<Piece> Knight::clone() const {
    std::cout<<"Constructor Clone Knight\n";
    return std::make_shared<Knight>(Knight(*this));
}

bool Knight::move(int x1, int y1, int x2, int y2,bool ok) {
    if (x1==x2 && y1==y2) return false;
    if(x1 == x2 - 2 && y1 == y2 - 1) return true;
    if(x1 == x2 - 2 && y1 == y2 + 1) return true;
    if(x1 == x2 + 2 && y1 == y2 - 1) return true;
    if(x1 == x2 + 2 && y1 == y2 + 1) return true;
    if(x1 == x2 - 1 && y1 == y2 - 2) return true;
    if(x1 == x2 - 1 && y1 == y2 + 2) return true;
    if(x1 == x2 + 1 && y1 == y2 - 2) return true;
    if(x1 == x2 + 1 && y1 == y2 + 2) return true;
    return false;
}

Knight::~Knight() {
    std::cout<<"Destructor Knight\n";
}