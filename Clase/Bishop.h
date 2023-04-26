#ifndef OOP_BISHOP_H
#define OOP_BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
private:
    void move() override;
public:
    Bishop();
    ~Bishop();
};


#endif //OOP_BISHOP_H
