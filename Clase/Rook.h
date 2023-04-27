#ifndef OOP_ROOK_H
#define OOP_ROOK_H

#include "Piece.h"
class Rook : public Piece{
private:

public:
    Rook();
    Rook(int);
    bool move(int,int,int,int) override;
    ~Rook();
};


#endif //OOP_ROOK_H
