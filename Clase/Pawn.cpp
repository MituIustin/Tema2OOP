#include "Pawn.h"

#include <iostream>
#include <cmath>

Pawn::Pawn() : name("pawn"){
    std::cout<<"Constructor Pawn\n";
    alive = true;
}

Pawn *Pawn::clone() const {
    std::cout<<"Constructor Clone Pawn\n";
    return new Pawn(*this);
}

Pawn::Pawn(int x): name("pawn") {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whitepawn.png", sf::IntRect(0,0,171,242));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/171), float(100.0/242));
    }
    else
    {
        texture.loadFromFile("Texturi/blackpawn.png", sf::IntRect(0,0,172,232));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/172), float(100.0/232));
    }
}

bool Pawn::move(int x1, int x2, int y1, int y2) {
    if(x2==y2 && abs(x1-y1)<=2) return true;
    return false;
}

Pawn::Pawn(const Pawn & other) : name(other.name) {
    std::cout<<"CC Pawn\n";
    alive = other.alive;
}

Pawn &Pawn::operator=(const Pawn & other) {
    std::cout<<"OP= Pawn\n";
    alive = other.alive;
    name = other.name;
    return *this;
}

Pawn::~Pawn() {
    std::cout<<"Destructor Pawn\n";
}