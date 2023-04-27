#ifndef OOP_QUEEN_H
#define OOP_QUEEN_H

#include "Piece.h"

class Queen : public  Piece{
private:

public:
    Queen();
    Queen(int);
    bool move(int,int,int,int) override;
    ~Queen();
};


#endif //OOP_QUEEN_H
