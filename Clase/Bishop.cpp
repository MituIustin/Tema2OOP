#include "Bishop.h"

#include <iostream>

Bishop::Bishop() {
    std::cout<<"Constructor Bishop\n";
    alive = true;
}

void Bishop::move() {

}

Bishop::~Bishop() {
    std::cout<<"Destructor Bishop\n";
}