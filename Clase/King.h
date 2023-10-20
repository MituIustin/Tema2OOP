#ifndef OOP_KING_H
#define OOP_KING_H

#include "Piece.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class King: public Piece {
    public: King();
    std::shared_ptr < Piece > clone() const override;
    bool move(int, int, int, int, bool) override;
    ~King();
};

#endif //OOP_KING_H
