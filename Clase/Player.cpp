#include "Player.h"
#include <iostream>
#include <memory>

#include "Bishop.h"
#include <memory>

Player::Player() {
    std::cout<<"Constructor Player\n";
}

void Player::create_bishops() {
    std::unique_ptr <Bishop> bishop1 = std::make_unique<Bishop>();
    std::unique_ptr <Bishop> bishop2 = std::make_unique<Bishop>();
    bishops.push_back(std::move(bishop1));
    bishops.push_back(std::move(bishop2));
}

void Player::create_pieces() {
    create_bishops();
    /*
    create_king();
    create_knights();
    create_pawns();
    create_queen();
    create_rooks();
    */
}