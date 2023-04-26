#ifndef OOP_KING_H
#define OOP_KING_H

#include "Piece.h"

class King : public Piece{
private:
    void move() override;
public:
    King();
    ~King();
};

#endif //OOP_KING_H
