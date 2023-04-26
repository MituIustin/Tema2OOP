#ifndef OOP_PAWN_H
#define OOP_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
private:
    void move() override;
public:
    Pawn();
    Pawn(int);
    ~Pawn();
};


#endif //OOP_PAWN_H
