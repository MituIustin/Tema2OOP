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
    number_of_pieces++;
    std::cout<<number_of_pieces<<" pieces have been created since the game started.\n";
}

Piece::Piece(const Piece & other):
row(other.row),
col(other.col),
name(other.name),
alive(other.alive),
texture(other.texture),
sprite(other.sprite)
{
    std::cout<<"CC Piece. \n";
}

Piece &Piece::operator=(const Piece & other) {
    name = other.name;
    alive = other.alive;
    texture = other.texture;
    sprite = other.sprite;
    row = other.row;
    col = other.col;
    return *this;
}


bool Piece::move(int x1,int x2,int x3,int x4) {
    if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0) return true;
    return false;
}

void Piece::set_sprite(sf::Sprite s) {
    sprite = s;
    sprite.setPosition(row*100,col*100);
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
    if(x >=0 && x<=9 && y>=0 && y<=9) sprite.setPosition(row*100, col*100);
    else throw NotValidXY();
}


Piece::~Piece() {
    std::cout<<"Destructor Piece\n";
    number_of_pieces--;
}
//CLASA ABSTRACTA