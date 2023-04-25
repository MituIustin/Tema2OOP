#ifndef OOP_PIECE_H
#define OOP_PIECE_H


class Piece {
private:

public:
    Piece();
    virtual void move() = 0;
    virtual ~Piece();
protected:
    bool alive;
};


#endif //OOP_PIECE_H

//CLASA ABSTRACTA