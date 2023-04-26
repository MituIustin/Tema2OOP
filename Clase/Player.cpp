#include "Player.h"
#include <iostream>
#include <memory>

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"

Player::Player() {
    std::cout<<"Constructor Player\n";
}

void Player::create_pawns() {
    for(int i=0; i<8; i++) {
        std::unique_ptr<Pawn> pawni = std::make_unique<Pawn>();
        pawns.push_back(std::move(pawni));
    }
}

void Player::create_queen() {
    std::unique_ptr<Queen> queen1 = std::make_unique<Queen>();
    queens.push_back(std::move(queen1));
}
void Player::create_rooks() {
    std::unique_ptr<Rook> rook1 = std::make_unique<Rook>();
    std::unique_ptr<Rook> rook2 = std::make_unique<Rook>();
    rooks.push_back(std::move(rook1));
    rooks.push_back(std::move(rook2));
}

void Player::create_knights() {
    std::unique_ptr<Knight> knight1 = std::make_unique<Knight>();
    std::unique_ptr<Knight> knight2 = std::make_unique<Knight>();
    knights.push_back(std::move(knight1));
    knights.push_back(std::move(knight2));
}

void Player::create_king() {
    std::unique_ptr<King> king1 = std::make_unique<King>();
    king = std::move(king1);
}

void Player::create_bishops() {
    std::unique_ptr <Bishop> bishop1 = std::make_unique<Bishop>();
    std::unique_ptr <Bishop> bishop2 = std::make_unique<Bishop>();
    bishops.push_back(std::move(bishop1));
    bishops.push_back(std::move(bishop2));
}

void Player::create_pieces() {
    create_bishops();
    create_king();
    create_knights();
    create_pawns();
    create_queen();
    create_rooks();
}