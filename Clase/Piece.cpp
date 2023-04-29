#include "Piece.h"
#include "Exception.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int Piece::number_of_pieces = 0;

Piece::Piece() {
    std::cout<<"Constructor Piece\n";
    alive = true;
    row = 9;
    col = 9;
}

Piece *Piece::clone() const {
    return nullptr;
}


bool Piece::move(int x1,int x2,int x3,int x4) {
    if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0) return true;
    return false;
}

void Piece::set_sprite(sf::Sprite s) {
    sprite = s;
}

bool Piece::get_alive() {
    return alive;
}

int Piece::get_col() {
    return col;
}

int Piece::get_row() {
    return row;
}

void Piece::set_alive(bool a) {
    alive = a;
}

sf::Sprite Piece::get_sprite() {
    return sprite;
}

void Piece::set_row_col(int x, int y) {
    col = x;
    row = y;
    try {
        if(x >=0 && x<=9 && y>=0 && y<=9) sprite.setPosition(row*100, col*100);
        else throw NotValidXY();
    }
    catch (const Exception& e) {
        std::cout<<"Error: "<<e.what();
    }
}


Piece::~Piece() {
    std::cout<<"Destructor Piece\n";
}
//CLASA ABSTRACTA