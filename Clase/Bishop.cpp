#include "Bishop.h"
#include <iostream>
#include <cmath>
Bishop::Bishop() : name("bishop"){
    std::cout<<"Constructor Bishop\n";
    alive = true;
}

Bishop *Bishop::clone() const {
    std::cout<<"Constructor Clone Bishop\n";
    return new Bishop(*this);
}

Bishop::Bishop(int x) : name("bishop"){
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whitebishop.png", sf::IntRect(0,0,163,275));
        sprite.setTexture(texture);
        sprite.setScale( float(100.0/163), float(100.0/275));
    }
    else
    {
        texture.loadFromFile("Texturi/blackbishop.png", sf::IntRect(0,0,178,272));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/178), float(100.0/272));

    }
    number_of_pieces++;
    std::cout<<"Number of pieces created  = "<<number_of_pieces<<"\n";
}

Bishop::Bishop(const Bishop & other) : name(other.name) {
    std::cout<<"CC Bishop\n";
    alive = other.alive;
}

Bishop &Bishop::operator=(const Bishop & other) {
    std::cout<<"OP= Bishop";
    name = other.name;
    return *this;
}

bool Bishop::move(int x1, int y1, int x2, int y2) {
    if(abs(x1-x2) == abs(y1-y2) || abs(x1-y1) == abs(x2-y2)) return true;
    return  false;
}

Bishop::~Bishop() {
    std::cout<<"Destructor Bishop\n";
}