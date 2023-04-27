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

public:
    int turn;
    Player();
    ~Player();

};


#endif //OOP_PLAYER_H
