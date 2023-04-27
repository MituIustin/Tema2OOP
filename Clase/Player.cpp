#include "Player.h"
#include <iostream>
#include <memory>

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"

#include <SFML/Graphics.hpp>

Player::Player() {
    std::cout<<"Constructor Player\n";
    turn =1;
}


Player::~Player() {
    std::cout<<"Destructor Player\n";
}