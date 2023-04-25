#include "Player.h"
#include <iostream>
#include <memory>

#include "Bishop.h"

Player::Player() {
    std::cout<<"Constructor Player\n";
}

void Player::create_bishops() {
    std::unique_ptr <Piece> bishop1;

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