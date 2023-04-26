#include "King.h"

#include <iostream>
#include <SFML/Graphics.hpp>

King::King() {
    std::cout<<"Constructor King\n";
    alive = true;
/*
    texture.loadFromFile("Texturi/blackking.png",sf::IntRect(0,0,100,100));
    texture.setSmooth(true);
    texture.setRepeated(false);
    sprite.setTexture(texture);
    sprite.setPosition(100,200);*/

}

void King::move() {

}

sf::Sprite King::get_sprite() {
    return sprite;
}

King::~King() {
    std::cout<<"Destructor King\n";
}