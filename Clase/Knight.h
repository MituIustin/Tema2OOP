#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include "Piece.h"
#include <string>

class Knight : public Piece{
private:
    std::string name;
public:
    Knight();
    explicit Knight(int);
    Knight(const Knight&);
    Knight& operator=(const Knight&);
    bool move(int,int,int,int) override;
    ~Knight();
};


#endif //OOP_KNIGHT_H
