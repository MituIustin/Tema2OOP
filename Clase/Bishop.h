#ifndef OOP_BISHOP_H
#define OOP_BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
private:

public:
    Bishop();
    explicit Bishop(int);
    bool move(int,int,int,int) override;
    ~Bishop();
};


#endif //OOP_BISHOP_H
