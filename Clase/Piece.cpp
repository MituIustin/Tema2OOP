#include "Piece.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Piece::Piece() {
    std::cout<<"\nConstructor Piece\n";
    alive = true;
}

void Piece::move() {

}

void Piece::set_sprite(sf::Sprite s) {
    sprite = s;
}

void Piece::set_texture(sf::Texture t) {
    texture = t;
}

sf::Sprite Piece::get_sprite() {
    return sprite;
}

sf::Texture Piece::get_texture() {
    return texture;
}

void Piece::set_row_col(int x, int y) {
    col = x;
    row = y;
    sprite.setPosition(row*100, col*100);
}

Piece::~Piece() {
    std::cout<<"Destructor Piece\n";
}
//CLASA ABSTRACTA