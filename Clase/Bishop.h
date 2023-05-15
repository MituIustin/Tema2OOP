#ifndef OOP_BISHOP_H
#define OOP_BISHOP_H

#include "Piece.h"
#include <string>
#include <memory>

class Bishop : public Piece{
public:
    Bishop();
    std::shared_ptr<Piece> clone() const override;
    bool move(int,int,int,int) override;
    ~Bishop();
};


#endif //OOP_BISHOP_H
