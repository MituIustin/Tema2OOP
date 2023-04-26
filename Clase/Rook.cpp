#include "Rook.h"
#include <iostream>

Rook::Rook() {
    std::cout<<"Constructor Rook\n";
    alive = true;
}

Rook::Rook(int x) {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whiterook.png", sf::IntRect(0,0,182,260));
        sprite.setTexture(texture);
        sprite.setScale(100.0/212, 100.0/290);
    }
    else
    {
        texture.loadFromFile("Texturi/blackrook.png", sf::IntRect(0,0,196,306));
        sprite.setTexture(texture);
        sprite.setScale(100.0/196, 100.0/306);

    }
}

void Rook::move() {

}

Rook::~Rook() {
    std::cout<<"Destructor Rook\n";
}