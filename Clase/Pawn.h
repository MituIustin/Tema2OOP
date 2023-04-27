#ifndef OOP_PAWN_H
#define OOP_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
private:

public:
    Pawn();
    explicit Pawn(int);
    bool move(int,int,int,int) override;
    ~Pawn();
};


#endif //OOP_PAWN_H
