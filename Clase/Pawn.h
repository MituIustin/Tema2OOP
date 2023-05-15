#ifndef OOP_PAWN_H
#define OOP_PAWN_H

#include "Piece.h"
#include <string>
#include <memory>

class Pawn : public Piece {
public:
    Pawn();
    std::shared_ptr<Piece> clone() const override;
    bool move(int,int,int,int) override;
    ~Pawn();
};


#endif //OOP_PAWN_H
