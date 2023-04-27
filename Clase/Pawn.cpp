#include "Pawn.h"

#include <iostream>
#include <cmath>

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

bool Pawn::move(int x1, int x2, int y1, int y2) {
    if(x2==y2 && abs(x1-y1)<=2) return true;

    return false;
}

Pawn::~Pawn() {
    std::cout<<"Destructor Pawn\n";
}