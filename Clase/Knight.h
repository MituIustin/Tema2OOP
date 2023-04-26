#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include "Piece.h"

class Knight : public Piece{
private:
    void move() override;
public:
    Knight();
    ~Knight();
};


#endif //OOP_KNIGHT_H
