#include "Piece.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Piece::Piece() {
    std::cout<<"\nConstructor Piece\n";
    alive = true;
    row = 9;
    col = 9;
}

bool Piece::move(int x1,int x2,int x3,int x4) {
    if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0) return true;
    return false;
}

void Piece::set_sprite(sf::Sprite s) {
    sprite = s;
}

sf::Sprite Piece::get_sprite() {
    return sprite;
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