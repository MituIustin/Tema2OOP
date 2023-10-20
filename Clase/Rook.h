#ifndef OOP_ROOK_H
#define OOP_ROOK_H

#include "Piece.h"

#include <string>
#include <memory>

class Rook: public Piece {
    public: Rook();
    std::shared_ptr < Piece > clone() const override;
    bool move(int, int, int, int, bool) override;
    ~Rook();
};

#endif //OOP_ROOK_H
