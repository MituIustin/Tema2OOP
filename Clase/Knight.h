#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include "Piece.h"

class Knight : public Piece{
private:

public:
    Knight();
    explicit Knight(int );
    bool move(int,int,int,int) override;
    ~Knight();
};


#endif //OOP_KNIGHT_H
