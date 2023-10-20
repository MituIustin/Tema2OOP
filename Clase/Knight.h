#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include "Piece.h"

#include <string>
#include <memory>

class Knight: public Piece {
    public: Knight();
    std::shared_ptr < Piece > clone() const override;
    bool move(int, int, int, int, bool) override;
    ~Knight();
};

#endif //OOP_KNIGHT_H
