#include "King.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
King::King() : name("king"){
    std::cout<<"Constructor King\n";
    alive = true;
}

King::King(int x): name("king") {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whiteking.png", sf::IntRect(0,0,188,309));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/218), float(100.0/339));
    }
    else
    {
        texture.loadFromFile("Texturi/blackking.png", sf::IntRect(0,0,196,306));
        sprite.setTexture(texture);
        sprite.setScale(float(100.0/226), float(100.0/336));
    }
}

King::King(const King &other) : name(other.name) {
    std::cout<<"CC King\n";
    alive = other.alive;
};

King &King::operator=(const King & other) {
    std::cout<<"OP= King\n";
    alive = other.alive;
    return *this;
}

bool King::move(int x1, int y1, int x2, int y2) {
    if(abs(x1-x2)<=1 && abs(y1-y2)<=1) return true;
    return false;
}


King::~King() {
    std::cout<<"Destructor King\n";
}