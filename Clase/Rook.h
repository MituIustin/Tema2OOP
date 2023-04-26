#ifndef OOP_ROOK_H
#define OOP_ROOK_H

#include "Piece.h"

class Rook : public Piece{
private:
    void move() override;
public:
    Rook();
    ~Rook();
};


#endif //OOP_ROOK_H
