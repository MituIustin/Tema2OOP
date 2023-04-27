#ifndef OOP_ROOK_H
#define OOP_ROOK_H

#include "Piece.h"
#include <string>

class Rook : public Piece{
private:
    std::string name;
public:
    Rook();
    explicit Rook(int);
    Rook (const Rook&);
    Rook & operator=(const Rook &);
    bool move(int,int,int,int) override;
    ~Rook();
};


#endif //OOP_ROOK_H
