#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "Piece.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"


#include <vector>
#include <memory>

class Player {
private:
    std::vector <std::unique_ptr<Bishop>> bishops;
    std::vector <std::unique_ptr<Knight>> knights;
    std::vector <std::unique_ptr<Rook>> rooks;
    std::vector <std::unique_ptr<Pawn>> pawns;
    std::vector <std::unique_ptr<Queen>> queens;       //promovare pion, dynamic cast?
    const std::unique_ptr<King> king;

    void create_king();
    void create_queen();
    void create_pawns();
    void create_knights();
    void create_bishops();
    void create_rooks();

public:
    Player();
    void create_pieces();


};


#endif //OOP_PLAYER_H
