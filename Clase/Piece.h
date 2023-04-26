#ifndef OOP_PIECE_H
#define OOP_PIECE_H

#include <SFML/Graphics.hpp>

class Piece {
private:

public:
    Piece();
    virtual void move() = 0;
    virtual ~Piece();

protected:
    bool alive;
    int row,col;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //OOP_PIECE_H

//CLASA ABSTRACTA