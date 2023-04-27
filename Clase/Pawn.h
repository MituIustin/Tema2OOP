#ifndef OOP_PAWN_H
#define OOP_PAWN_H

#include "Piece.h"
#include <string>

class Pawn : public Piece {
private:
    std::string name;
public:
    Pawn();
    explicit Pawn(int);
    Pawn * clone() const override;
    Pawn(const Pawn&);
    Pawn & operator=(const Pawn&);
    bool move(int,int,int,int) override;
    ~Pawn();
};


#endif //OOP_PAWN_H
