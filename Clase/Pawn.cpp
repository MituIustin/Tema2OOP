#include "Pawn.h"

#include <iostream>

Pawn::Pawn() {
    std::cout<<"Constructor Pawn\n";
    alive = true;
}

Pawn::Pawn(int x) {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whitepawn.png", sf::IntRect(0,0,171,242));
        sprite.setTexture(texture);
        sprite.setScale(100.0/171, 100.0/242);
    }
    else
    {
        texture.loadFromFile("Texturi/blackpawn.png", sf::IntRect(0,0,172,232));
        sprite.setTexture(texture);
        sprite.setScale(100.0/172, 100.0/232);

    }
}

void Pawn::move() {

}

Pawn::~Pawn() {
    std::cout<<"Destructor Pawn\n";
}