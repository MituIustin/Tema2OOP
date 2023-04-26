#include "Queen.h"

#include <iostream>

Queen::Queen() {
    std::cout<<"Constructor Queen\n";
    alive = true;
}

Queen::Queen(int x) {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whitequeen.png", sf::IntRect(0,0,183,286));
        sprite.setTexture(texture);
        sprite.setScale(100.0/200, 100.0/300);
    }
    else
    {
        texture.loadFromFile("Texturi/blackqueen.png", sf::IntRect(0,0,182,276));
        sprite.setTexture(texture);
        sprite.setScale(100.0/200, 100.0/300);

    }
}

void Queen::move() {

}

Queen::~Queen() {
    std::cout<<"Destructor Queen\n";
}