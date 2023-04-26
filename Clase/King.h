#ifndef OOP_KING_H
#define OOP_KING_H

#include "Piece.h"
#include <SFML/Graphics.hpp>

class King : public Piece{
private:
    void move() override;
public:
    King();
    King(int);
    King(const King&) ;
    ~King();
};

#endif //OOP_KING_H
