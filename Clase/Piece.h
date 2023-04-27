#ifndef OOP_PIECE_H
#define OOP_PIECE_H

#include <SFML/Graphics.hpp>

class Piece {
private:
    int row,col;
public:
    Piece();
    virtual Piece * clone() const = 0;
    virtual ~Piece();
    virtual bool move(int,int,int,int) =0;
    void set_row_col(int, int);
    int get_row();
    int get_col();
    bool get_alive();
    void set_alive(bool);
    void set_sprite(sf::Sprite);
    sf::Sprite get_sprite();

protected:
    static int number_of_pieces;
    bool alive;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //OOP_PIECE_H

//CLASA ABSTRACTA