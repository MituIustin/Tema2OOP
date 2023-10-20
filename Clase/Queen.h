#ifndef OOP_QUEEN_H
#define OOP_QUEEN_H

#include "Piece.h"

#include <string>
#include <memory>

class Queen: public Piece {
    public: Queen();
    std::shared_ptr < Piece > clone() const override;
    bool move(int, int, int, int, bool) override;
    ~Queen();
};

#endif //OOP_QUEEN_H
