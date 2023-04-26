#include "King.h"

#include <iostream>
#include <SFML/Graphics.hpp>

King::King() {
    std::cout<<"Constructor King\n";
    alive = true;

}

King::King(int x) {
    alive = true;
    if(x==0)
    {
        texture.loadFromFile("Texturi/whiteking.png", sf::IntRect(0,0,188,309));
        sprite.setTexture(texture);
        sprite.setScale(100.0/218, 100.0/339);
    }
    else
    {
        texture.loadFromFile("Texturi/blackking.png", sf::IntRect(0,0,196,306));
        sprite.setTexture(texture);
        sprite.setScale(100.0/226, 100.0/336);
    }
}

King::King(const King &other)
{
    alive = other.alive;
    std::cout<<"CC King\n";
};


void King::move() {

}


King::~King() {
    std::cout<<"Destructor King\n";
}