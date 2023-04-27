#ifndef OOP_PIECE_H
#define OOP_PIECE_H

#include <SFML/Graphics.hpp>

class Piece {
private:
public:
    Piece();
    virtual bool move(int,int,int,int) =0;
    sf::Sprite get_sprite();
    void set_sprite(sf::Sprite);
    virtual ~Piece();
    bool alive;
    void set_row_col(int, int);
    int row,col;
protected:
    sf::Texture texture;
    sf::Sprite sprite;

};


#endif //OOP_PIECE_H

//CLASA ABSTRACTA