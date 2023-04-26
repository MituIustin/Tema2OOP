#include "King.h"

#include <iostream>

King::King() {
    std::cout<<"Constructor King\n";
    alive = true;
}

void King::move() {

}

King::~King() {
    std::cout<<"Destructor King\n";
}