#include "Knight.h"
#include <iostream>

Knight::Knight(): name("knight") {
    std::cout<<"Constructor Knight\n";
    alive = true;
}

Knight *Knight::clone() const {
    std::cout<<"Constructor Clone Knight\n";
    return new Knight(*this);
}

Knight::Knight(int x) : name("knight"){
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whiteknight.png", sf::IntRect(0,0,183,295));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/183), float(100.0/295));
    }
    else
    {
        texture.loadFromFile("Texturi/blackknight.png", sf::IntRect(0,0,195,279));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/195), float(100.0/279));

    }
    number_of_pieces++;
    std::cout<<"Number of pieces created  = "<<number_of_pieces<<"\n";
}

Knight::Knight(const Knight & other) : name(other.name){
    std::cout<<"CC Knight\n";
    alive = other.alive;
}

Knight &Knight::operator=(const Knight & other) {
    std::cout<<"OP= Knight\n";
    alive = other.alive;
    name = other.name;
    return *this;
}

bool Knight::move(int x1, int y1, int x2, int y2) {
    if(x1 == x2 - 2 && y1 == y2 - 1) return true;
    if(x1 == x2 - 2 && y1 == y2 + 1) return true;
    if(x1 == x2 + 2 && y1 == y2 - 1) return true;
    if(x1 == x2 + 2 && y1 == y2 + 1) return true;
    if(x1 == x2 - 1 && y1 == y2 - 2) return true;
    if(x1 == x2 - 1 && y1 == y2 + 2) return true;
    if(x1 == x2 + 1 && y1 == y2 - 2) return true;
    if(x1 == x2 + 1 && y1 == y2 + 2) return true;
    return false;
}

Knight::~Knight() {
    std::cout<<"Destructor Knight\n";
}