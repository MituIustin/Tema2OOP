#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "Piece.h"

#include <vector>
#include <memory>

class Player {
private:
    std::vector <std::unique_ptr<Piece>> pieces;
    void create_king();
    void create_queen();
    void create_pawns();
    void create_knights();
    void create_bishops();
    void create_rooks();
    void create_pieces();
public:
    Player();
};


#endif //OOP_PLAYER_H
