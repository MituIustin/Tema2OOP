#include "Queen.h"
#include "Exception.h"
#include <iostream>

Queen::Queen() : name("queen") {
    std::cout<<"Constructor Queen\n";
    alive = true;
}

Queen *Queen::clone() const {
    std::cout<<"Constructor Clone Queen\n";
    return new Queen(*this);
}

Queen::Queen(int x): name("queen") {
    alive = true;
    try {
        if(x==0)
        {
            if (!texture.loadFromFile("Texturi/whitequeen.png", sf::IntRect(0,0,183,286)))
                throw NoTexture();
            sprite.setTexture(texture);
            sprite.setScale(float(100.0/200), float(100.0/300));
        }
        else
        {
            if (!texture.loadFromFile("Texturi/blackqueen.png", sf::IntRect(0,0,182,276)))
                throw NoTexture();
            sprite.setTexture(texture);
            sprite.setScale(float(100.0/200), float(100.0/300));

        }
    }
    catch (const Exception & e)
    {
        std::cout<<"Error: "<<e.what();
    }
    number_of_pieces++;
    std::cout<<"Number of pieces created  = "<<number_of_pieces<<"\n";
}

bool Queen::move(int x1, int y1, int x2, int y2) {
    if(abs(x1-x2) == abs(y1-y2) || abs(x1-y1) == abs(x2-y2)) return true;
    bool var = true;
    if(x1 != x2 && y1 != y2) var = false;
    return  var;
}

Queen::Queen(const Queen & other) :name(other.name) {
    std::cout<<"CC Queen\n";
    alive = other.alive;
}

Queen &Queen::operator=(const Queen & other) {
    std::cout<<"OP= Queen\n";
    alive = other.alive;
    name = other.name;
    return *this;
}

Queen::~Queen() {
    std::cout<<"Destructor Queen\n";
}