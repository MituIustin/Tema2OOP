#include "Knight.h"
#include <iostream>

Knight::Knight() {
    std::cout<<"Constructor Knight\n";
    alive = true;
}

Knight::Knight(int x) {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whiteknight.png", sf::IntRect(0,0,183,295));
        sprite.setTexture(texture);
        sprite.setScale(100.0/183, 100.0/295);
    }
    else
    {
        texture.loadFromFile("Texturi/blackknight.png", sf::IntRect(0,0,195,279));
        sprite.setTexture(texture);
        sprite.setScale(100.0/195, 100.0/279);

    }
}

void Knight::move() {

}

Knight::~Knight() {
    std::cout<<"Destructor Knight\n";
}