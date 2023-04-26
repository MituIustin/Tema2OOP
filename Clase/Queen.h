#ifndef OOP_QUEEN_H
#define OOP_QUEEN_H

#include "Piece.h"

class Queen : public  Piece{
private:
    void move() override;
public:
    Queen();
    ~Queen();
};


#endif //OOP_QUEEN_H
