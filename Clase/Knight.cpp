#include "Knight.h"
#include <iostream>

Knight::Knight() {
    std::cout<<"Constructor Knight\n";
    alive = true;
}

void Knight::move() {

}

Knight::~Knight() {
    std::cout<<"Destructor Knight\n";
}