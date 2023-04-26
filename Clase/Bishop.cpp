#include "Bishop.h"

#include <iostream>

Bishop::Bishop() {
    std::cout<<"Constructor Bishop\n";
    alive = true;
}

Bishop::Bishop(int x) {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whitebishop.png", sf::IntRect(0,0,163,275));
        sprite.setTexture(texture);
        sprite.setScale(100.0/163, 100.0/275);
    }
    else
    {
        texture.loadFromFile("Texturi/blackbishop.png", sf::IntRect(0,0,178,272));
        sprite.setTexture(texture);
        sprite.setScale(100.0/178, 100.0/272);

    }
}

void Bishop::move() {

}

Bishop::~Bishop() {
    std::cout<<"Destructor Bishop\n";
}