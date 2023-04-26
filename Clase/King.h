#ifndef OOP_KING_H
#define OOP_KING_H

#include "Piece.h"
#include <SFML/Graphics.hpp>

class King : public Piece{
private:
    void move() override;
public:
    King();
    sf::Sprite get_sprite();
    ~King();
};

#endif //OOP_KING_H
