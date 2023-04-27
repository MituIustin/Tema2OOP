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

bool Queen::move(int x1, int y1, int x2, int y2) {
    if(abs(x1-x2) == abs(y1-y2) || abs(x1-y1) == abs(x2-y2)) return true;
    bool var = true;
    if(x1 != x2 && y1 != y2) var = false;
    return  var;
}

Queen::~Queen() {
    std::cout<<"Destructor Queen\n";
}