#ifndef OOP_QUEEN_H
#define OOP_QUEEN_H

#include "Piece.h"
#include <string>

class Queen : public  Piece{
private:
    std::string name;
public:
    Queen();
    Queen * clone() const override;
    Queen(const Queen&);
    Queen & operator=(const Queen&);
    bool move(int,int,int,int) override;
    ~Queen();
};


#endif //OOP_QUEEN_H
