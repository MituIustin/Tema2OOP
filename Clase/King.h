#ifndef OOP_KING_H
#define OOP_KING_H

#include "Piece.h"
#include <SFML/Graphics.hpp>

class King : public Piece{
private:

public:
    King();
    King(int);
    King(const King&) ;
    bool move(int,int,int,int) override;
    ~King();
};

#endif //OOP_KING_H
