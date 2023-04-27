#include "Rook.h"
#include <iostream>

Rook::Rook() : name("rook") {
    std::cout<<"Constructor Rook\n";
    alive = true;
}

Rook *Rook::clone() const {
    std::cout<<"Constructor Clone Rook\n";
    return new Rook(*this);
}

Rook::Rook(int x) : name("rook") {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whiterook.png", sf::IntRect(0,0,182,260));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/212), float(100.0/290));
    }
    else
    {
        texture.loadFromFile("Texturi/blackrook.png", sf::IntRect(0,0,196,306));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/196), float(100.0/306));

    }
    number_of_pieces++;
    std::cout<<"Number of pieces created  = "<<number_of_pieces<<"\n";
}

bool Rook::move(int x1, int y1, int x2, int y2) {
    bool var = true;
    if(x1 != x2 && y1 != y2) var = false;
    return var;
}

Rook::Rook(const Rook & other) : name(other.name){
    std::cout<<"CC Rook\n";
    alive = other.alive;
}

Rook &Rook::operator=(const Rook & other) {
    std::cout<<"OP= Rook\n";
    alive = other.alive;
    name = other.name;
    return *this;
}

Rook::~Rook() {
    std::cout<<"Destructor Rook\n";
}